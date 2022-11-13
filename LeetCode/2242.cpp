class Solution {
public:
    int maximumScore(vector<int> &values, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> adj(values.size());
        for (vector<int> &edge : edges) {
            adj[edge[0]].push_back({ values[edge[1]], edge[1] });
            adj[edge[1]].push_back({ values[edge[0]], edge[0] });
        }
        
        for (vector<pair<int, int>> &a : adj)
            sort(a.rbegin(), a.rend());
        
        int res = -1;
        for (vector<int> &edge : edges) {
            int b = edge[0], c = edge[1];
            
            for (int ai = 0; ai < adj[b].size() && ai < 3; ai++) {
                int a = adj[b][ai].second;
                if (a == b || a == c)
                    continue;
                
                for (int di = 0; di < adj[c].size() && di < 3; di++) {
                    int d = adj[c][di].second;
                    if (a == d || b == d || c == d)
                        continue;
                    
                    res = max(res, values[a] + values[b] + values[c] + values[d]);
                }
            }
        }
        return res;
    }
};