class Solution {
public:
    int minFlips(vector<vector<int>> &a) {
        int res = 0;
        for (int ly = 0, ry = a.size() - 1; ly < ry; ly++, ry--) {
            for (int lx = 0, rx = a[0].size() - 1; lx < rx; lx++, rx--) {
                int count = a[ly][lx] + a[ly][rx] + a[ry][lx] + a[ry][rx];
                res += min(count, 4 - count);
            }
        }

        int ones = 0, flips = 0;
        if (a.size() % 2) {
            for (int l = 0, r = a[0].size() - 1; l < r; l++, r--) {
                if (a[a.size() / 2][l] != a[a.size() / 2][r])
                    flips++;
                else if (a[a.size() / 2][l])
                    ones += 2;
            }
        }
        if (a[0].size() % 2) {
            for (int l = 0, r = a.size() - 1; l < r; l++, r--) {
                if (a[l][a[0].size() / 2] != a[r][a[0].size() / 2])
                    flips++;
                else if (a[l][a[0].size() / 2])
                    ones += 2;
            }
        }

        if (ones % 4 && !flips)
            flips += 2;
        if (a.size() % 2 && a[0].size() % 2 && a[a.size() / 2][a[0].size() / 2])
            flips++;
        
        res += flips;
        return res;
    }
};