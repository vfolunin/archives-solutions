class Solution {
public:
    int findLonelyPixel(vector<vector<char>> &a) {
        vector<int> row(a.size()), col(a[0].size());
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x] == 'B') {
                    row[y]++;
                    col[x]++;
                }
            }
        }

        int res = 0;
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                res += a[y][x] == 'B' && row[y] == 1 && col[x] == 1;
        return res;
    }
};