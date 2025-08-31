class Solution {
public:
    int uniquePaths(vector<vector<int>> &a) {
        const int MOD = 1e9 + 7;
        vector ways(a.size(), vector(a[0].size(), vector<int>(2)));
        ways[0][0][0] = 1;

        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (y) {
                    ways[y][x][0] = ways[y - 1][x][1];
                    if (!a[y - 1][x])
                        ways[y][x][0] = (ways[y][x][0] + ways[y - 1][x][0]) % MOD;
                }
                if (x) {
                    ways[y][x][1] = ways[y][x - 1][0];
                    if (!a[y][x - 1])
                        ways[y][x][1] = (ways[y][x][1] + ways[y][x - 1][1]) % MOD;
                }
            }
        }

        return (ways.back().back()[0] + ways.back().back()[1]) % MOD;
    }
};