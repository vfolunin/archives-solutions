class Solution {
    bool check(vector<vector<int>> a) {
        int h = a.size(), w = a[0].size();

        long long lSum = 0, rSum = 0;
        unordered_multiset<long long> lValues, rValues;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                rSum += a[y][x];
                rValues.insert(a[y][x]);
            }
        }

        for (int x = 0; x + 1 < w; x++) {
            for (int y = 0; y < h; y++) {
                lSum += a[y][x];
                rSum -= a[y][x];
                lValues.insert(a[y][x]);
                rValues.erase(rValues.find(a[y][x]));
            }

            long long diff = lSum - rSum;
            if (!diff) {
                return 1;
            } else if (diff > 0) {
                if (h == 1) {
                    if (diff == a[0][0] || diff == a[0][x])
                        return 1;
                } else if (x == 0) {
                    if (diff == a[0][0] || diff == a[h - 1][0])
                        return 1;
                } else {
                    if (lValues.find(diff) != lValues.end())
                        return 1;
                }
            } else {
                if (h == 1) {
                    if (-diff == a[0][x + 1] || -diff == a[0][w - 1])
                        return 1;
                } else if (x + 2 == w) {
                    if (-diff == a[0][w - 1] || -diff == a[h - 1][w - 1])
                        return 1;
                } else {
                    if (rValues.find(-diff) != rValues.end())
                        return 1;
                }
            }
        }

        return 0;
    }

    vector<vector<int>> transpose(vector<vector<int>> &a) {
        int h = a[0].size(), w = a.size();
        vector<vector<int>> res(h, vector<int>(w));
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res[y][x] = a[x][y];
        return res;
    }

public:
    bool canPartitionGrid(vector<vector<int>> &a) {
        return check(a) || check(transpose(a));
    }
};