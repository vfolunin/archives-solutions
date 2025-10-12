class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color, bool &isBipartite) {
        visited[v] = color;
        for (int to : graph[v]) {
            if (!visited[to])
                dfs(graph, to, visited, 3 - color, isBipartite);
            else if (visited[to] == color)
                isBipartite = 0;
        }
    }

    bool can(vector<vector<int>> &points, int limit) {
        vector<vector<int>> graph(points.size());
        for (int a = 0; a < points.size(); a++) {
            for (int b = a + 1; b < points.size(); b++) {
                if (abs(points[a][0] - points[b][0]) + abs(points[a][1] - points[b][1]) < limit) {
                    graph[a].push_back(b);
                    graph[b].push_back(a);
                }
            }
        }

        vector<int> visited(graph.size());
        bool isBipartite = 1;
        for (int v = 0; v < graph.size() && isBipartite; v++)
            if (!visited[v])
                dfs(graph, v, visited, 1, isBipartite);
        return isBipartite;
    }

public:
    int maxPartitionFactor(vector<vector<int>> &points) {
        if (points.size() == 2)
            return 0;
            
        int l = 0, r = 1;
        while (can(points, r))
            r *= 2;
        
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(points, m))
                l = m;
            else
                r = m;
        }

        return l;
    }
};