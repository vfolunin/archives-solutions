class Solution {
    int bfs(vector<vector<int>> &graph) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

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

        return dist.back();
    }

public:
    vector<int> shortestDistanceAfterQueries(int vertexCount, vector<vector<int>> &queries) {
        vector<vector<int>> graph(vertexCount);
        for (int v = 0; v + 1 < vertexCount; v++)
            graph[v].push_back(v + 1);

        vector<int> res;
        for (vector<int> &query : queries) {
            graph[query[0]].push_back(query[1]);
            res.push_back(bfs(graph));
        }
        return res;
    }
};