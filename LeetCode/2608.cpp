class Solution {
    int bfs(vector<unordered_set<int>> &graph, int start, int finish) {
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
    int findShortestCycle(int vertexCount, vector<vector<int>> &edges) {
        vector<unordered_set<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        int res = 1e9;
        for (vector<int> &edge : edges) {
            graph[edge[0]].erase(edge[1]);
            graph[edge[1]].erase(edge[0]);

            res = min(res, bfs(graph, edge[0], edge[1]) + 1);

            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        return res != 1e9 ? res : -1;
    }
};