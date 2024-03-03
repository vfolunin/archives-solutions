class Solution {
    int getOps(vector<vector<int>> &a, int figure, int background) {
        int res = 0;
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a.size(); x++) {
                if (y <= a.size() / 2 && (y == x || y + x == a.size() - 1) ||
                    y > a.size() / 2 && x == a.size() / 2)
                    res += a[y][x] != figure;
                else
                    res += a[y][x] != background;
            }
        }
        return res;
    }

public:
    int minimumOperationsToWriteY(vector<vector<int>> &a) {
        int res = 1e9;
        for (int figure = 0; figure < 3; figure++)
            for (int background = 0; background < 3; background++)
                if (figure != background)
                    res = min(res, getOps(a, figure, background));
        return res;
    }
};