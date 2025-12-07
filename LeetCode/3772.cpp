class Solution {
    void dfs1(vector<vector<int>> &graph, int v, int p, vector<int> &delta, vector<int> &treeRes) {
        treeRes[v] = delta[v];

        for (int to : graph[v]) {
            if (to == p)
                continue;

            dfs1(graph, to, v, delta, treeRes);

            treeRes[v] += max(treeRes[to], 0);
        }
    }

    void dfs2(vector<vector<int>> &graph, int v, int p, vector<int> &treeRes, vector<int> &res) {
        res[v] = treeRes[v];

        for (int to : graph[v]) {
            if (to == p)
                continue;

            treeRes[v] -= max(treeRes[to], 0);
            treeRes[to] += max(treeRes[v], 0);

            dfs2(graph, to, v, treeRes, res);

            treeRes[to] -= max(treeRes[v], 0);
            treeRes[v] += max(treeRes[to], 0);
        }
    }

public:
    vector<int> maxSubgraphScore(int vertexCount, vector<vector<int>> &edges, vector<int> &delta) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        replace(delta.begin(), delta.end(), 0, -1);

        vector<int> treeRes(vertexCount);
        dfs1(graph, 0, -1, delta, treeRes);

        vector<int> res(vertexCount);
        dfs2(graph, 0, -1, treeRes, res);
        return res;
    }
};