class Solution {
    void dfs(vector<vector<int>> &graph, int v, int p, vector<int> &dist) {
        dist[v] = (p == -1 ? 0 : dist[p] + 1);
        for (int to : graph[v])
            if (dist[to] == -1)
                dfs(graph, to, v, dist);
    }

public:
    vector<int> closestNode(int vertexCount, vector<vector<int>> &edges, vector<vector<int>> &queries) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            vector<int> distA(vertexCount, -1);
            dfs(graph, queries[i][0], -1, distA);
            vector<int> distB(vertexCount, -1);
            dfs(graph, queries[i][1], -1, distB);
            vector<int> distC(vertexCount, -1);
            dfs(graph, queries[i][2], -1, distC);

            int dist = 1e9;
            for (int v = 0; v < vertexCount; v++) {
                if (distA[v] + distB[v] == distA[queries[i][1]] && dist > distC[v]) {
                    dist = distC[v];
                    res[i] = v;
                }
            }
        }
        return res;
    }
};