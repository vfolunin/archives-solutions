class Solution {
public:
    int countSubmatrices(vector<vector<int>> &p, int limit) {
        int res = 0;
        for (int y = 0; y < p.size(); y++) {
            for (int x = 0; x < p[0].size(); x++) {
                if (y)
                    p[y][x] += p[y - 1][x];
                if (x)
                    p[y][x] += p[y][x - 1];
                if (y && x)
                    p[y][x] -= p[y - 1][x - 1];
                res += p[y][x] <= limit;
            }
        }
        return res;
    }
};