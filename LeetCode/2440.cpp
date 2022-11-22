class Solution {
    int dfs(vector<vector<int>> &graph, int v, int p, vector<int> &a, int mod) {
        int sum = a[v];
        
        for (int to : graph[v])
            if (to != p)
                sum += dfs(graph, to, v, a, mod);
        
        return sum == mod ? 0 : sum;
    }
    
public:
    int componentValue(vector<int> &a, vector<vector<int>> &edges) {
        vector<vector<int>> graph(a.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int sum = accumulate(a.begin(), a.end(), 0);
        for (int partCount = a.size(); 1; partCount--)
            if (sum % partCount == 0 && !dfs(graph, 0, -1, a, sum / partCount))
                return partCount - 1;
    }
};