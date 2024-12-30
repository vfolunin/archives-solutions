class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>> &a, int targetValue) {
        const long long MOD = 1e9 + 7;
        vector ways(a.size(), vector(a[0].size(), vector<long long>(16)));
        ways[0][0][a[0][0]] = 1;

        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                for (int value = 0; value < 16; value++) {
                    if (y)
                        ways[y][x][value] = (ways[y][x][value] + ways[y - 1][x][value ^ a[y][x]]) % MOD;
                    if (x)
                        ways[y][x][value] = (ways[y][x][value] + ways[y][x - 1][value ^ a[y][x]]) % MOD;
                }
            }
        }

        return ways.back().back()[targetValue];
    }
};