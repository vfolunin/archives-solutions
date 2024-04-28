class Solution {
    vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
        vector<int> dist(graph.size(), 1e9);
        set<pair<int, int>> q;

        dist[start] = 0;
        q.insert({ dist[start], start });

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
    vector<bool> findAnswer(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }

        vector<int> distStart = dijkstra(graph, 0);
        vector<int> distFinish = dijkstra(graph, vertexCount - 1);

        vector<bool> res(edges.size());
        for (int i = 0; i < edges.size(); i++)
            res[i] = distStart[edges[i][0]] + edges[i][2] + distFinish[edges[i][1]] == distStart[vertexCount - 1] ||
                     distStart[edges[i][1]] + edges[i][2] + distFinish[edges[i][0]] == distStart[vertexCount - 1];
        return res;
    }
};