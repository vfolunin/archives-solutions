class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &a) {
        sort(a.begin(), a.end());
        set<vector<int>> subsets;
        
        for (int mask = 0; mask < (1 << a.size()); mask++) {
            vector<int> subset;
            for (int bit = 0; bit < a.size(); bit++)
                if (mask & (1 << bit))
                    subset.push_back(a[bit]);
            subsets.insert(subset);
        }
        
        return { subsets.begin(), subsets.end() };
    }
};