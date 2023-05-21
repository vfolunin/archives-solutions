class Solution {
    long long dijkstra(vector<vector<int>> &graph, vector<vector<int>> &edges, int start, int finish) {
        vector<long long> dist(graph.size(), 1e18);
        set<pair<long long, int>> q;

        dist[start] = 0;
        q.insert({ dist[start], start });

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (int ei : graph[v]) {
                int to = v == edges[ei][0] ? edges[ei][1] : edges[ei][0], weight = edges[ei][2];

                if (dist[to] > dist[v] + weight) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + weight;
                    q.insert({ dist[to], to });
                }
            }
        }

        return dist[finish];
    }

public:
    vector<vector<int>> modifiedGraphEdges(int vertexCount, vector<vector<int>> &edges, int start, int finish, int target) {
        vector<vector<int>> graph(vertexCount);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(i);
            graph[edges[i][1]].push_back(i);
            if (edges[i][2] == -1)
                edges[i][2] = 2e9;
        }
        
        if (dijkstra(graph, edges, start, finish) < target)
            return {};

        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][2] == 2e9) {
                edges[i][2] = 1;
                long long dist = dijkstra(graph, edges, start, finish);
                if (dist <= target) {
                    edges[i][2] = target - dist + 1;
                    return edges;
                }
            }
        }

        if (dijkstra(graph, edges, start, finish) == target)
            return edges;
        else
            return {};
    }
};