class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }
    
public:
    int maximumRequests(int vertexCount, vector<vector<int>> &edges) {
        int res = 0;
        
        for (int mask = 0; mask < (1 << edges.size()); mask++) {
            vector<int> delta(vertexCount);
            
            for (int bit = 0; bit < edges.size(); bit++) {
                if (mask & (1 << bit)) {
                    delta[edges[bit][0]]--;
                    delta[edges[bit][1]]++;
                }
            }
            
            if (count(delta.begin(), delta.end(), 0) == delta.size())
                res = max(res, ones(mask));
        }
        
        return res;
    }
};