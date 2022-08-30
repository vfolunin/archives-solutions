class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        for (int to : graph[v])
            if (!visited[to])
                dfs(graph, to, visited);
    }
    
public:
    int maximumDetonation(vector<vector<int>> &circles) {
        vector<vector<int>> graph(circles.size());
        for (int a = 0; a < circles.size(); a++) {
            for (int b = 0; b < circles.size(); b++) {
                long long dx = circles[a][0] - circles[b][0];
                long long dy = circles[a][1] - circles[b][1];
                long long r = circles[a][2];
                if (dx * dx + dy * dy <= r * r)
                    graph[a].push_back(b);
            }
        }
        
        int res = 0;        
        for (int v = 0; v < circles.size(); v++) {
            vector<int> visited(circles.size());
            dfs(graph, v, visited);
            res = max<int>(res, count(visited.begin(), visited.end(), 1));
        }        
        return res;
    }
};