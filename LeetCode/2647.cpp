class Solution {
public:
    vector<vector<int>> colorRed(int n) {
        vector<vector<int>> res = { { 1, 1 } };
        for (int y = 2; y <= n; y++) {
            if (y <= n % 4) {
                res.push_back({ y, 1 });
                res.push_back({ y, y * 2 - 1 });
            } else if ((n - y) % 4 == 3) {
                res.push_back({ y, 1 });
            } else if ((n - y) % 4 == 2) {
                for (int x = 3; x < y * 2; x += 2)
                    res.push_back({ y, x });
            } else if ((n - y) % 4 == 1) {
                res.push_back({ y, 2 });
            } else {
                for (int x = 1; x < y * 2; x += 2)
                    res.push_back({ y, x });
            }
        }
        return res;
    }
};