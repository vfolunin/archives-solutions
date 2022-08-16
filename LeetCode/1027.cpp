class Solution {
public:
    int longestArithSeqLength(vector<int> &a) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
        
        vector<vector<int>> res(a.size(), vector<int>(a.size()));
        int maxRes = 2;
        
        for (int i = 0; i < a.size(); i++) {
            for (int pi = 0; pi < i; pi++) {
                res[pi][i] = 2;
                
                if (pos.count(a[pi] - (a[i] - a[pi]))) {
                    vector<int> &p = pos[a[pi] - (a[i] - a[pi])];
                    
                    auto it = lower_bound(p.begin(), p.end(), pi);
                    if (it == p.begin())
                        continue;
                    
                    int ppi = *prev(it);
                    res[pi][i] = max(res[pi][i], res[ppi][pi] + 1);                
                    maxRes = max(maxRes, res[pi][i]);
                }
            }
        }
        
        return maxRes;
        
    }
};