class Solution {
    vector<int> bfs(vector<vector<int>> &graph, const int start) {
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
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
        vector<vector<int>> graph(patience.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> dist = bfs(graph, 0);
        
        int res = 0;
        for (int v = 1; v < graph.size(); v++) {
            int time = dist[v] * 2;
            int lastStart = (time - 1) / patience[v] * patience[v];
            res = max(res, lastStart + time + 1);
        }
        return res;
    }
};