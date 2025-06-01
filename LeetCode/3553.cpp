struct Graph {
    vector<vector<pair<int, int>>> graph;
    vector<vector<int>> ancestor;
    vector<int> l, r, depth;
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

    int distance(int a, int b) {
        int l = lca(a, b);
        int da = depth[a] - depth[l];
        int db = depth[b] - depth[l];
        return da + db;
    }
};

class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>> &edges, vector<vector<int>> &queries) {
        Graph graph(edges.size() + 1);
        for (vector<int> &edge : edges)
            graph.addEdge(edge[0], edge[1], edge[2]);

        graph.prepare(0);

        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++) {
            int a = queries[i][0], b = queries[i][1], c = queries[i][2];
            res[i] = (graph.distance(a, b) + graph.distance(a, c) + graph.distance(b, c)) / 2;
        }
        return res;
    }
};