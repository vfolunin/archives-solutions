class Solution {
public:
    int minimumOperations(vector<vector<int>> &a) {
        int res = 0;
        for (int y = 1; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                int delta = max(0, a[y - 1][x] + 1 - a[y][x]);
                a[y][x] += delta;
                res += delta;
            }
        }
        return res;
    }
};