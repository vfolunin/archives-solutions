class Solution {
public:
    int sumCounts(vector<int> &a) {
        int res = 0;
        for (int l = 0; l < a.size(); l++) {
            unordered_set<int> values;
            for (int r = l; r < a.size(); r++) {
                values.insert(a[r]);
                res += values.size() * values.size();
            }
        }
        return res;
    }
};