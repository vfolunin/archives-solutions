class Solution {
public:
    int countArrays(vector<int> &a, vector<vector<int>> &bounds) {
        int l = bounds[0][0], r = bounds[0][1];
        for (int i = 1; i < a.size(); i++) {
            l = max(l + a[i] - a[i - 1], bounds[i][0]);
            r = min(r + a[i] - a[i - 1], bounds[i][1]);
        }
        return max(r - l + 1, 0);
    }
};