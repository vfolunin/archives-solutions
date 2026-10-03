const long long MOD = 1e9 + 7;

using Matrix = vector<vector<long long>>;

Matrix &operator *= (Matrix &a, const Matrix &b) {
    long long a00 = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    long long a01 = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    long long a10 = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    long long a11 = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;

    a[0][0] = a00;
    a[0][1] = a01;
    a[1][0] = a10;
    a[1][1] = a11;
    return a;
}

struct Graph {
    vector<vector<int>> graph, ancestor;
    vector<int> l, r;
    vector<vector<Matrix>> matrix;
    int timer = 0;

    Graph(int vertexCount) :
        graph(vertexCount),
        ancestor(vertexCount, vector<int>(15)),
        l(vertexCount),
        r(vertexCount),
        matrix(vertexCount, vector<Matrix>(15)) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void dfs(int v, int parent) {
        l[v] = timer++;

        ancestor[v][0] = parent;
        for (int i = 1; i < ancestor[v].size(); i++) {
            ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];
            matrix[v][i] = matrix[v][i - 1];
            matrix[v][i] *= matrix[ancestor[v][i - 1]][i - 1];
        }

        for (int to : graph[v])
            if (to != parent)
                dfs(to, v);

        r[v] = timer++;
    }

    void prepare(int root) {
        dfs(root, root);
    }

    bool isAncestor(int a, int b) {
        return l[a] <= l[b] && r[b] <= r[a];
    }

    int lca(int a, int b) {
        if (isAncestor(a, b))
            return a;
        if (isAncestor(b, a))
            return b;

        for (int i = ancestor[a].size() - 1; i >= 0; i--)
            if (!isAncestor(ancestor[a][i], b))
                a = ancestor[a][i];

        return ancestor[a][0];
    }

    long long ways(int a, int b, int card) {
        Matrix m = { { 1, 0 },{ 0, 1 } };

        if (a != b) {
            for (int i = ancestor[a].size() - 1; i >= 0; i--) {
                if (!isAncestor(ancestor[a][i], b)) {
                    m *= matrix[a][i];
                    a = ancestor[a][i];
                }
            }

            m *= matrix[a][0];
        }

        return (m[card][0] + m[card][1]) % MOD;
    }
};

class Solution {
public:
    int distinctPaths(int vertexCount, vector<int> &parent, vector<vector<int>> &gates, vector<vector<int>> &queries) {
        Graph graph(vertexCount);
        for (int v = 0; v < vertexCount; v++) {
            if (v)
                graph.addEdge(parent[v], v);

            graph.matrix[v][0] = { { gates[v][1], gates[v][2] },{ gates[v][2], gates[v][0] } };
        }

        graph.prepare(0);

        int res = 0;
        for (vector<int> &query : queries) {
            int a = query[0], aCard = query[1], b = query[2], bCard = query[3];
            int lca = graph.lca(a, b);
            long long aWays = graph.ways(a, lca, aCard);
            long long bWays = graph.ways(b, lca, bCard);
            res ^= aWays * bWays % MOD;
        }
        return res;
    }
};