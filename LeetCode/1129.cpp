class Solution {
    vector<int> bfs(vector<vector<vector<int>>> &graph, int start) {
        vector<vector<int>> dist(graph.size(), vector<int>(2, 1e9));
        queue<pair<int, int>> q;

        dist[start][0] = dist[start][1] = 0;
        q.push({ start, 0 });
        q.push({ start, 1 });

        while (!q.empty()) {
            auto [v, color] = q.front();
            q.pop();

            for (int to : graph[v][color]) {
                if (dist[to][!color] > dist[v][color] + 1) {
                    dist[to][!color] = dist[v][color] + 1;
                    q.push({ to, !color });
                }
            }
        }

        vector<int> res(graph.size());
        for (int v = 0; v < graph.size(); v++) {
            res[v] = min(dist[v][0], dist[v][1]);
            if (res[v] == 1e9)
                res[v] = -1;
        }
        return res;
    }
    
public:
    vector<int> shortestAlternatingPaths(int vertexCount, vector<vector<int>> edges0,
        vector<vector<int>> edges1) {
        vector<vector<vector<int>>> graph(vertexCount, vector<vector<int>>(2));
        for (vector<int> &edge : edges0)
            graph[edge[0]][0].push_back(edge[1]);
        for (vector<int> &edge : edges1)
            graph[edge[0]][1].push_back(edge[1]);

        return bfs(graph, 0);
    }
};