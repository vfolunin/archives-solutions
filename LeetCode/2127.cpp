class Solution {
    int getCycleSize(vector<int> &favorite, int v, vector<int> &visited) {
        unordered_map<int, int> seen;
        
        for (int i = 0; 1; i++) {
            if (seen.count(v))
                return i - seen[v];
            seen[v] = i;
            
            if (visited[v])
                return 0;
            visited[v] = 1;
            
            v = favorite[v];
        }
    }
    
    int getMaxCycleSize(vector<int> &favorite) {
        vector<int> visited(favorite.size());
        int res = 0;
        
        for (int v = 0; v < visited.size(); v++)
            if (!visited[v])
                res = max(res, getCycleSize(favorite, v, visited));
        
        return res;
    }
    
    vector<vector<int>> getReverseGraph(vector<int> &favorite) {
        vector<vector<int>> graph(favorite.size());
        for (int v = 0; v < favorite.size(); v++)
            graph[favorite[v]].push_back(v);
        return graph;
    }
    
    int getMaxChainSize(vector<vector<int>> &graph, int v, int p) {
        int res = 1;
        for (int to : graph[v])
            if (to != p)
                res = max(res, getMaxChainSize(graph, to, v) + 1);
        return res;
    }
    
public:
    int maximumInvitations(vector<int> &favorite) {
        int res1 = getMaxCycleSize(favorite), res2 = 0;
        
        vector<vector<int>> graph = getReverseGraph(favorite);
        for (int v = 0; v < favorite.size(); v++)
            if (v < favorite[v] && favorite[favorite[v]] == v)
                res2 += getMaxChainSize(graph, v, favorite[v]) + getMaxChainSize(graph, favorite[v], v);
        
        return max(res1, res2);
    }
};