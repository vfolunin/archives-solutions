class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>> &a) {
        int h = a.size(), w = a[0].size();

        vector<vector<int>> p(h, vector<int>(w));
        vector<vector<int>> px(h, vector<int>(w));
        int res = 0;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                p[y][x] = (a[y][x] == 'X') - (a[y][x] == 'Y');
                px[y][x] = (a[y][x] == 'X');
                if (y) {
                    p[y][x] += p[y - 1][x];
                    px[y][x] += px[y - 1][x];
                }
                if (x) {
                    p[y][x] += p[y][x - 1];
                    px[y][x] += px[y][x - 1];
                }
                if (y && x) {
                    p[y][x] -= p[y - 1][x - 1];
                    px[y][x] -= px[y - 1][x - 1];
                }
                res += !p[y][x] && px[y][x];
            }
        }

        return res;
    }
};