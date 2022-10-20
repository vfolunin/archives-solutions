class Solution {
    void rec(vector<vector<int>> &graph, int v, int p, vector<int> &values,
             int depth, vector<vector<pair<int, int>>> &ancestors, vector<int> &res) {
        int ancestor, minDist = 1e9;
        
        for (int i = 1; i < ancestors.size(); i++) {
            if (!ancestors[i].empty() && gcd(i, values[v]) == 1) {
                int dist = depth - ancestors[i].back().second;
                if (minDist > dist) {
                    ancestor = ancestors[i].back().first;
                    minDist = dist;
                }
            }
        }
        
        if (minDist != 1e9)
            res[v] = ancestor;
        
        ancestors[values[v]].push_back({ v, depth });
        
        for (int to : graph[v])
            if (to != p)
                rec(graph, to, v, values, depth + 1, ancestors, res);
        
        ancestors[values[v]].pop_back();
    }
    
public:
    vector<int> getCoprimes(vector<int> &values, vector<vector<int>> &edges) {
        vector<vector<int>> graph(values.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<vector<pair<int, int>>> ancestors(51);
        vector<int> res(values.size(), -1);
        rec(graph, 0, -1, values, 0, ancestors, res);
        return res;
    }
};