class Solution {
public:
    int diagonalSum(vector<vector<int>> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += a[i][i] + a[i][a.size() - 1 - i];
        if (a.size() % 2)
            res -= a[a.size() / 2][a.size() / 2];
        return res;
    }
};