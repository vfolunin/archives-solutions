struct Graph {
    vector<vector<pair<int, int>>> graph;
    vector<vector<int>> ancestor;
    vector<int> l, r;
    vector<long long> depth;
    int timer = 0;

    Graph(int vertexCount) :
        graph(vertexCount),
        ancestor(vertexCount, vector<int>(20)),
        l(vertexCount),
        r(vertexCount),
        depth(vertexCount) {}

    void addEdge(int a, int b, int weight) {
        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    void dfs(int v, int parent, int weight) {
        depth[v] = (v == parent ? 0 : depth[parent] + weight);
        l[v] = timer++;

        ancestor[v][0] = parent;
        for (int i = 1; i < ancestor[v].size(); i++)
            ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];

        for (auto &[to, weight] : graph[v])
            if (to != parent)
                dfs(to, v, weight);

        r[v] = timer++;
    }

    void prepare(int root) {
        dfs(root, root, 0);
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

    long long distance(int a, int b) {
        int l = lca(a, b);
        long long da = depth[a] - depth[l];
        long long db = depth[b] - depth[l];
        return da + db;
    }

    int median(int v, long long dist, bool aToB) {
        for (int i = ancestor[v].size() - 1; i >= 0; i--) {
            long long part = distance(v, ancestor[v][i]);
            if (aToB && part < dist || !aToB && part <= dist) {
                v = ancestor[v][i];
                dist -= part;
            }
        }
        return aToB ? ancestor[v][0] : v;
    }
};

class Solution {
public:
    vector<int> findMedian(int vertexCount, vector<vector<int>> &edges, vector<vector<int>> &queries) {
        Graph graph(edges.size() + 1);
        for (vector<int> &edge : edges)
            graph.addEdge(edge[0], edge[1], edge[2]);

        graph.prepare(0);

        vector<int> res(queries.size(), -1);
        for (int i = 0; i < res.size(); i++) {
            int a = queries[i][0], b = queries[i][1], l = graph.lca(a, b);
            long long ab = graph.distance(a, b), al = graph.distance(a, l);
            if (a == b)
                res[i] = a;
            else if (al * 2 >= ab)
                res[i] = graph.median(a, (ab + 1) / 2, 1);
            else
                res[i] = graph.median(b, ab - (ab + 1) / 2, 0);
        }
        return res;
    }
};