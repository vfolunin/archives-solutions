class Solution {
public:
    int countCompleteSubarrays(vector<int> &a) {
        unordered_set<int> values(a.begin(), a.end());
        int res = 0;
        
        for (int l = 0; l < a.size(); l++) {
            unordered_set<int> curValues;
            for (int r = l; r < a.size(); r++) {
                curValues.insert(a[r]);
                res += curValues.size() == values.size();
            }
        }
        
        return res;
    }
};