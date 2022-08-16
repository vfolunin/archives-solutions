class Solution {
    vector<double> dijkstra(vector<vector<pair<int, double>>> &graph, int start) {
        vector<double> dist(graph.size(), 1e9);
        dist[start] = 0;
        set<pair<int, int>> q = { { dist[start], start } };

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (auto &[to, w] : graph[v]) {
                if (dist[to] > dist[v] + w) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + w;
                    q.insert({ dist[to], to });
                }
            }
        }

        return dist;
    }
    
public:
    double maxProbability(int vertexCount, vector<vector<int>> &edges, vector<double> &prob, int start, int finish) {
        vector<vector<pair<int, double>>> graph(vertexCount);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({ edges[i][1], -log(prob[i]) });
            graph[edges[i][1]].push_back({ edges[i][0], -log(prob[i]) });
        }
        
        vector<double> dist = dijkstra(graph, start);
        return dist[finish] != 1e9 ? exp(-dist[finish]) : 0.0;
    }
};