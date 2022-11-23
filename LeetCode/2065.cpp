class Solution {
    void rec(vector<vector<pair<int, int>>> &graph, int v, vector<int> &visited,
             int time, int timeLimit, vector<int> &a, int sum, int &res) {
        if (!visited[v])
            sum += a[v];
        visited[v]++;
        
        if (!v)
            res = max(res, sum);
        
        for (auto &[to, weight] : graph[v])
            if (time + weight <= timeLimit)
                rec(graph, to, visited, time + weight, timeLimit, a, sum, res);
        
        visited[v]--;
        if (!visited[v])
            sum -= a[v];
    }
    
public:
    int maximalPathQuality(vector<int> &a, vector<vector<int>> &edges, int timeLimit) {
        vector<vector<pair<int, int>>> graph(a.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }

        vector<int> visited(a.size());
        int res = 0;
        rec(graph, 0, visited, 0, timeLimit, a, 0, res);
        return res;
    }
};