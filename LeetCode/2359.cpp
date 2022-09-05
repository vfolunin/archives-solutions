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
    int closestMeetingNode(vector<int> &to, int a, int b) {
        vector<vector<int>> graph(to.size());
        for (int v = 0; v < graph.size(); v++)
            if (to[v] != -1)
                graph[v].push_back(to[v]);
        
        vector<int> distA = bfs(graph, a);
        vector<int> distB = bfs(graph, b);
        
        int res = -1;
        for (int v = 0; v < graph.size(); v++)
            if (distA[v] != 1e9 && distB[v] != 1e9 && (res == -1 || max(distA[res], distB[res]) > max(distA[v], distB[v])))
                res = v;
        return res;
    }
};