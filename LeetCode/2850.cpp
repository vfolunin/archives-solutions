class Solution {
public:
    int minimumMoves(vector<vector<int>> &a) {
        int zeroY = -1, zeroX = -1;
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a.size(); x++) {
                if (!a[y][x]) {
                    zeroY = y;
                    zeroX = x;
                    break;
                }
            }
        }

        if (zeroY == -1)
            return 0;

        int res = 1e9;
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                if (a[y][x] > 1) {
                    a[y][x]--;
                    a[zeroY][zeroX]++;
                    res = min(res, abs(y - zeroY) + abs(x - zeroX) + minimumMoves(a));
                    a[y][x]++;
                    a[zeroY][zeroX]--;
                }
            }
        }
        return res;
    }
};