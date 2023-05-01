class Solution {
    int dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish) {
        vector<int> dist(graph.size(), 2e9);
        dist[start] = 0;
        set<pair<int, int>> q = { { dist[start], start } };

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            if (v == finish)
                return dist[v];

            for (auto &[to, w] : graph[v]) {
                if (dist[to] > dist[v] + w) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + w;
                    q.insert({ dist[to], to });
                }
            }
        }

        return 2e9;
    }

public:
    int minimumCost(vector<int> &start, vector<int> &finish, vector<vector<int>> &roads) {
        vector<vector<int>> points;
        for (int i = 0; i < roads.size(); i++) {
            points.push_back({ roads[i][0], roads[i][1] });
            points.push_back({ roads[i][2], roads[i][3] });
        }
        points.push_back(start);
        points.push_back(finish);

        int vertexCount = points.size();
        vector<vector<pair<int, int>>> graph(vertexCount);

        for (int v = 0; v < vertexCount; v++)
            for (int to = 0; to < vertexCount; to++)
                graph[v].push_back({ to, abs(points[v][0] - points[to][0]) + abs(points[v][1] - points[to][1] )});
        
        for (int i = 0; i < roads.size(); i++)
            graph[i * 2].push_back({ i * 2 + 1, roads[i][4] });
        
        return dijkstra(graph, points.size() - 2, points.size() - 1);
    }
};