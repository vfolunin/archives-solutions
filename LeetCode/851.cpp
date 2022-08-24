class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &bonus, vector<int> &res) {
        res[v] = v;
        
        for (int to : graph[v]) {
            if (res[to] == -1)
                dfs(graph, to, bonus, res);
            
            if (bonus[res[v]] > bonus[res[to]])
                res[v] = res[to];
        }
    }
    
public:
    vector<int> loudAndRich(vector<vector<int>> &edges, vector<int> &bonus) {
        vector<vector<int>> graph(bonus.size());
        for (vector<int> &edge : edges)
            graph[edge[1]].push_back(edge[0]);
        
        vector<int> res(graph.size(), -1);
        for (int v = 0; v < graph.size(); v++)
            if (res[v] == -1)
                dfs(graph, v, bonus, res);
        
        return res;
    }
};