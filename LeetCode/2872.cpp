class Solution {
    long long dfs(vector<vector<int>> &graph, int v, int p, vector<int> &a, int divisor, int &res) {
        long long sum = a[v];
        
        for (int to : graph[v])
            if (to != p)
                sum += dfs(graph, to, v, a, divisor, res);
        
        res += sum % divisor == 0;
        return sum % divisor;
    }
    
public:
    int maxKDivisibleComponents(int vertexCount, vector<vector<int>> &edges, vector<int> &a, int divisor) {
        vector<vector<int>> graph(vertexCount);
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int res = 0;
        dfs(graph, 0, -1, a, divisor, res);
        return res;
    }
};