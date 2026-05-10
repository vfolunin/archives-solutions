class Solution {
    bool bfs(vector<vector<pair<int, int>>> &graph, int start, int finish, int limit, int threshold) {
        vector<int> dist(graph.size(), 1e9);
        deque<int> q;

        dist[start] = 0;
        q.push_back(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop_front();

            for (auto &[to, weight] : graph[v]) {
                if (weight > threshold && dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push_back(to);
                } else if (weight <= threshold && dist[to] > dist[v]) {
                    dist[to] = dist[v];
                    q.push_front(to);
                }
            }
        }

        return dist[finish] <= limit;
    }

public:
    int minimumThreshold(int vertexCount, vector<vector<int>> &edges, int start, int finish, int limit) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }

        int l = -1, r = 2e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (bfs(graph, start, finish, limit,m))
                r = m;
            else
                l = m;
        }
        return r < 2e9 ? r : -1;
    }
};