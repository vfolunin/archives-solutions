class Solution {
    int dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish, int jumpLimit) {
        vector<vector<int>> dist(graph.size(), vector<int>(jumpLimit + 1, 1e9));
        set<tuple<int, int, int>> q;

        dist[start][0] = 0;
        q.insert({ dist[start][0], start, 0 });

        while (!q.empty()) {
            auto [d, v, jumps] = *q.begin();
            q.erase(q.begin());

            for (auto &[to, weight] : graph[v]) {
                if (dist[to][jumps] > dist[v][jumps] + weight) {
                    q.erase({ dist[to][jumps], to, jumps });
                    dist[to][jumps] = dist[v][jumps] + weight;
                    q.insert({ dist[to][jumps], to, jumps });
                }
                if (jumps < jumpLimit && dist[to][jumps + 1] > dist[v][jumps]) {
                    q.erase({ dist[to][jumps + 1], to, jumps + 1 });
                    dist[to][jumps + 1] = dist[v][jumps];
                    q.insert({ dist[to][jumps + 1], to, jumps + 1 });
                }
            }
        }

        return *min_element(dist[finish].begin(), dist[finish].end());
    }

public:
    int shortestPathWithHops(int vertexCount, vector<vector<int>> &edges, int start, int finish, int jumpLimit) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }

        return dijkstra(graph, start, finish, jumpLimit);
    }
};