class Solution {
    bool matches(vector<vector<int>> &a, vector<string> &b, int fromY, int fromX) {
        unordered_map<char, int> c2i;
        unordered_map<int, char> i2c;

        for (int y = 0; y < b.size(); y++) {
            for (int x = 0; x < b[0].size(); x++) {
                if (c2i.count(b[y][x])) {
                    if (c2i[b[y][x]] != a[fromY + y][fromX + x])
                        return 0;
                } else if (isdigit(b[y][x])) {
                    if (b[y][x] - '0' != a[fromY + y][fromX + x])
                        return 0;
                } else {
                    if (i2c.count(a[fromY + y][fromX + x]))
                        return 0;
                    c2i[b[y][x]] = a[fromY + y][fromX + x];
                    i2c[a[fromY + y][fromX + x]] = b[y][x];
                }
            }
        }

        return 1;
    }

public:
    vector<int> findPattern(vector<vector<int>> &a, vector<string> &b) {
        for (int y = 0; y + b.size() <= a.size(); y++)
            for (int x = 0; x + b[0].size() <= a[0].size(); x++)
                if (matches(a, b, y, x))
                    return { y, x };
        return { -1, -1 };
    }
};