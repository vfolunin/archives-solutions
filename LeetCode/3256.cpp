class Solution {
public:
    long long maximumValueSum(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();

        vector<vector<pair<int, int>>> pairs(h);
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++)
                pairs[y].push_back({ a[y][x], x });

            sort(pairs[y].rbegin(), pairs[y].rend());
            pairs[y].resize(3);
        }

        long long res = -1e18;

        for (int y0 = 0; y0 < h; y0++) {
            for (auto &[value0, x0] : pairs[y0]) {
                for (int y1 = y0 + 1; y1 < h; y1++) {
                    for (auto &[value1, x1] : pairs[y1]) {
                        if (x0 == x1)
                            continue;

                        for (int y2 = y1 + 1; y2 < h; y2++) {
                            for (auto &[value2, x2] : pairs[y2]) {
                                if (x0 == x2 || x1 == x2)
                                    continue;

                                res = max(res, (long long)value0 + value1 + value2);
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};