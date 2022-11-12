class Solution {
    void bfs(vector<vector<int>> &graph, int v, vector<int> &values, vector<int> &seen) {
        queue<int> q;
        
        seen[values[v]] = 1;
        q.push(v);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            for (int to : graph[v]) {
                if (!seen[values[to]]) {
                    seen[values[to]] = 1;
                    q.push(to);
                }
            }
        }
    }
    
public:
    vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &values) {
        vector<int> res(values.size(), 1);
        
        int v = find(values.begin(), values.end(), 1) - values.begin();
        if (v == values.size())
            return res;
        
        vector<vector<int>> graph(values.size());
        for (int v = 0; v < graph.size(); v++)
            if (parents[v] != -1)
                graph[parents[v]].push_back(v);
        
        vector<int> seen(1e5 + 2);
        int mex = 1;
        for ( ; v != -1; v = parents[v]) {
            bfs(graph, v, values, seen);
            while (seen[mex])
                mex++;
            res[v] = mex;
        }
        
        return res;
    }
};