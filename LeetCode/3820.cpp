class Solution {
    vector<int> bfs(vector<vector<int>> &graph, int start) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : graph[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return dist;
    }

public:
    int specialNodes(int vertexCount, vector<vector<int>> &edges, int x, int y, int z) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> distX = bfs(graph, x);
        vector<int> distY = bfs(graph, y);
        vector<int> distZ = bfs(graph, z);

        int res = 0;
        for (int v = 0; v < vertexCount; v++) {
            vector<long long> dist = { distX[v], distY[v], distZ[v] };
            sort(dist.begin(), dist.end());
            res += dist[0] * dist[0] + dist[1] * dist[1] == dist[2] * dist[2];
        }
        return res;
    }
};