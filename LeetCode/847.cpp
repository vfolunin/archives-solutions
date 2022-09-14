class Solution {
    int rec(vector<vector<int>> &dist, int mask, int last, vector<vector<int>> &memo) {
        int &res = memo[mask][last];
        if (res != -1)
            return res;
        
        if (!(mask & (mask - 1)))
            return res = 0;
        
        res = 1e9;
        for (int prev = 0; prev < dist.size(); prev++)
            if ((mask & (1 << prev)) && prev != last)
                res = min(res, rec(dist, mask ^ (1 << last), prev, memo) + dist[prev][last]);
        return res;
    }
    
public:
    int shortestPathLength(vector<vector<int>> &graph) {
        vector<vector<int>> dist(graph.size(), vector<int>(graph.size(), 1e9));
        
        for (int v = 0; v < graph.size(); v++)
            dist[v][v] = 0;
        
        for (int v = 0; v < graph.size(); v++)
            for (int to : graph[v])
                dist[v][to] = min(dist[v][to], 1);
        
        for (int v = 0; v < graph.size(); v++)
            for (int a = 0; a < graph.size(); a++)
                for (int b = 0; b < graph.size(); b++)
                    dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);
        
        int res = 1e9;
        
        vector<vector<int>> memo(1 << graph.size(), vector<int>(graph.size(), -1));
        for (int last = 0; last < graph.size(); last++)
            res = min(res, rec(dist, (1 << graph.size()) - 1, last, memo));
        
        return res;
    }
};