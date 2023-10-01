class Solution {
    void dfs(vector<int> &to, int v, vector<int> &visited, vector<int> &from, vector<int> &res) {
        visited[v] = 1;

        if (visited[to[v]] == 0) {
            from[to[v]] = v;
            dfs(to, to[v], visited, from, res);
        } else if (visited[to[v]] == 1) {
            int cycleSize = 0;
            for (int cycleV = v; cycleV != from[to[v]]; cycleV = from[cycleV])
                cycleSize++;
 
            for (int cycleV = v; cycleV != from[to[v]]; cycleV = from[cycleV])
                res[cycleV] = cycleSize;
        }
                
        visited[v] = 2;
    }
    
    int dfs2(vector<int> &to, int v, vector<int> &res) {
        if (res[v])
            return res[v];
        return res[v] = 1 + dfs2(to, to[v], res);
    }

public:
    vector<int> countVisitedNodes(vector<int> &to) {
        vector<int> visited(to.size());
        vector<int> from(to.size(), -1);
        vector<int> res(to.size());

        for (int v = 0; v < to.size(); v++)
            if (!visited[v])
                dfs(to, v, visited, from, res);
        
        for (int v = 0; v < to.size(); v++)
            if (!res[v])
                dfs2(to, v, res);
        
        return res;
    }
};
