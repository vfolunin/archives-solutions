class Graph {
    vector<vector<pair<int, int>>> graph;

public:
    Graph(int vertexCount, vector<vector<int>> &edges) : graph(vertexCount) {
        for (vector<int> &edge : edges)
            addEdge(edge);
    }
    
    void addEdge(const vector<int> &edge) {
        graph[edge[0]].push_back({ edge[1], edge[2] });
    }
    
    int shortestPath(int start, int finish) {
        vector<int> dist(graph.size(), 1e9);
        set<pair<int, int>> q;

        dist[start] = 0;
        q.insert({ dist[start], start });

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            if (v == finish)
                return dist[v];

            for (auto &[to, weight] : graph[v]) {
                if (dist[to] > dist[v] + weight) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + weight;
                    q.insert({ dist[to], to });
                }
            }
        }

        return -1;
    }
};