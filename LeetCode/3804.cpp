class Solution {
public:
    int centeredSubarrays(vector<int> &a) {
        int res = 0;
        for (int l = 0; l < a.size(); l++) {
            unordered_set<int> values;
            int sum = 0;
            for (int r = l; r < a.size(); r++) {
                values.insert(a[r]);
                sum += a[r];
                res += values.count(sum);
            }
        }
        return res;
    }
};