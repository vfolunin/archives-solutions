class Solution {
    void rec(vector<vector<int>> &a, int y, int x, vector<int> &row, vector<int> &col, int cur, int &res) {
        if (res <= cur)
            return;

        if (y == a.size()) {
            for (int i = 0; i < a.size(); i++)
                for (int j = 0; j < a[0].size(); j++)
                    if (a[i][j] && !row[i] && !col[j])
                        return;
            
            res = cur;
            return;
        }

        if (x == a[0].size()) {
            rec(a, y + 1, 0, row, col, cur, res);
            return;
        }

        rec(a, y, x + 1, row, col, cur, res);

        if (a[y][x]) {
            row[y]++;
            col[x]++;
            rec(a, y, x + 1, row, col, cur + 1, res);
            row[y]--;
            col[x]--;
        }
    }

public:
    int removeOnes(vector<vector<int>> &a) {
        vector<int> row(a.size()), col(a[0].size());
        int res = a.size();
        rec(a, 0, 0, row, col, 0, res);
        return res;
    }
};