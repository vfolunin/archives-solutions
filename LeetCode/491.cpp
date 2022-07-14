class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int> &a) {
        set<vector<int>> res;
        
        for (int mask = 0; mask < (1 << a.size()); mask++) {
            vector<int> subsequence;
            
            for (int bit = 0; bit < a.size(); bit++) {
                if (mask & (1 << bit)) {
                    if (!subsequence.empty() && subsequence.back() > a[bit]) {
                        subsequence.clear();
                        break;
                    }
                    subsequence.push_back(a[bit]);
                }
            }
            
            if (subsequence.size() > 1)
                res.insert(subsequence);
        }
        
        return { res.begin(), res.end() };
    }
};