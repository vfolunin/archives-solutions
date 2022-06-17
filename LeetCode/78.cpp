class Solution {
public:
    vector<vector<int>> subsets(vector<int> &a) {
        vector<vector<int>> res;

        for (int mask = 0; mask < (1 << a.size()); mask++) {
            vector<int> subset;
            for (int bit = 0; bit < a.size(); bit++)
                if (mask & (1 << bit))
                    subset.push_back(a[bit]);
            res.push_back(subset);
        }
        
        return res;
    }
};