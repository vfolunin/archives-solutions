class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &a) {
        sort(a.begin(), a.end());
        
        vector<vector<int>> res;
        do {
            res.push_back(a);
        } while (next_permutation(a.begin(), a.end()));
        
        return res;
    }
};