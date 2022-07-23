class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        for (int to : graph[v])
            if (!visited[to])
                dfs(graph, to, visited);
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>> &graph) {
        vector<int> visited(graph.size());
        dfs(graph, 0, visited);
        return !count(visited.begin(), visited.end(), 0);
    }
};