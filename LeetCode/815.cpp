class Solution {
    int bfs(vector<vector<int>> &graph, int start, int finish) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            if (v == finish)
                return dist[v];

            for (int to : graph[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return 1e9;
    }

public:
    int numBusesToDestination(vector<vector<int>> &routes, int start, int finish) {
        vector<vector<int>> graph(1e6 + 500);
        for (int bus = 0; bus < routes.size(); bus++) {
            for (int stop : routes[bus]) {
                graph[stop].push_back(1e6 + bus);
                graph[1e6 + bus].push_back(stop);
            }
        }
        
        int dist = bfs(graph, start, finish);
        return dist != 1e9 ? dist / 2 : -1;
    }
};