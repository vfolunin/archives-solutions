class Solution {
    int bfs(vector<vector<int>> &graph) {
        vector<vector<int>> dist(2, vector<int>(graph.size(), 1e9));
        queue<pair<int, int>> q;

        dist[0][0] = 0;
        q.push({ 0, 0 });

        while (!q.empty()) {
            auto [v, type] = q.front();
            q.pop();

            for (int to : graph[v]) {
                if (dist[0][to] > dist[type][v] + 1) {
                    dist[0][to] = dist[type][v] + 1;
                    q.push({ to, 0 });
                } else if (dist[1][to] > dist[type][v] + 1 && dist[type][v] + 1 > dist[0][to]) {
                    dist[1][to] = dist[type][v] + 1;
                    q.push({ to, 1 });
                }
            }
        }

        return dist[1].back();
    }
    
public:
    int secondMinimum(int vertexCount, vector<vector<int>> &edges, int time, int change) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
        
        int secondDist = bfs(graph);
        
        int res = 0;
        for (int i = 0; i < secondDist; i++) {
            if (res / change % 2)
                res = (res / change + 1) * change;
            res += time;
        }
        return res;
    }
};