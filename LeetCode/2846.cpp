struct Graph {
    vector<vector<pair<int, int>>> graph;
    vector<vector<int>> ancestor;
    vector<int> l, r;
    int timer = 0;
    vector<vector<int>> count;

    Graph(int vertexCount) :
        graph(vertexCount),
        ancestor(vertexCount, vector<int>(15)),
        l(vertexCount),
        r(vertexCount),
        count(vertexCount, vector<int>(26)) {}

    void addEdge(int a, int b, int weight) {
        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    void dfs(int v, int parent, int weight) {
        if (v != parent) {
            count[v] = count[parent];
            count[v][weight]++;
        }
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
        dfs(root, root, -1);
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

    int getCost(int a, int b) {
        int l = lca(a, b), sumCount = 0, maxCount = 0;
        for (int weight = 0; weight < count[a].size(); weight++) {
            int weightCount = count[a][weight] + count[b][weight] - 2 * count[l][weight];
            sumCount += weightCount;
            maxCount = max(maxCount, weightCount);
        }
        return sumCount - maxCount;
    }
};

class Solution {
public:
    vector<int> minOperationsQueries(int vertexCount, vector<vector<int>> &edges, vector<vector<int>> &queries) {
        Graph graph(vertexCount);
        for (vector<int> &edge : edges)
            graph.addEdge(edge[0], edge[1], edge[2] - 1);
        graph.prepare(0);

        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = graph.getCost(queries[i][0], queries[i][1]);
        return res;
    }
};