class Solution {
    bool bfs(vector<vector<int>> &graph, int limit) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (v == graph.size() - 1)
                return 1;
            
            if (dist[v] == limit)
                continue;

            for (int to : graph[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return 0;
    }

    bool can(int vertexCount, vector<vector<int>> &edges, int limit, int money) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            if (edge[2] <= money) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
        }
        return bfs(graph, limit);
    }

public:
    int minCost(int vertexCount, vector<vector<int>> &edges, int limit) {
        int l = -1, r = 2e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(vertexCount, edges, limit, m))
                r = m;
            else
                l = m;
        }
        return r != 2e9 ? r : -1;
    }
};