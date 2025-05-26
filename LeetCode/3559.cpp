struct Graph {
    vector<vector<int>> graph, ancestor;
    vector<int> l, r, depth;
    int timer = 0;

    Graph(int vertexCount) :
        graph(vertexCount),
        ancestor(vertexCount, vector<int>(20)),
        l(vertexCount),
        r(vertexCount),
        depth(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void dfs(int v, int parent) {
        depth[v] = (v == parent ? 0 : depth[parent] + 1);
        l[v] = timer++;

        ancestor[v][0] = parent;
        for (int i = 1; i < ancestor[v].size(); i++)
            ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];

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

    int distance(int a, int b) {
        int l = lca(a, b);
        int da = depth[a] - depth[l];
        int db = depth[b] - depth[l];
        return da + db;
    }
};

class Solution {
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1 % mod;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries) {
        Graph graph(edges.size() + 1);
        for (vector<int> &edge : edges) 
            graph.addEdge(edge[0] - 1, edge[1] - 1);
        graph.prepare(0);

        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++) {
            int a = queries[i][0] - 1, b = queries[i][1] - 1;
            if (a != b)
                res[i] = binPow(2, graph.distance(a, b) - 1, 1e9 + 7);
        }
        return res;
    }
};
