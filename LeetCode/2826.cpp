class Solution {
    int getSum(vector<int> &p, int l, int r) {
        if (l > r)
            return 0;
        return p[r] - (l ? p[l - 1] : 0);
    }

public:
    int minimumOperations(vector<int> &a) {
        vector<vector<int>> p(3, vector<int>(a.size()));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < a.size(); j++) {
                p[i][j] = a[j] == i + 1;
                if (j)
                    p[i][j] += p[i][j - 1];
            }
        }

        int res = 0;
        for (int l = 0; l <= a.size(); l++)
            for (int r = l; r <= a.size(); r++)
                res = max(res, getSum(p[0], 0, l - 1) + getSum(p[1], l, r - 1) + getSum(p[2], r, a.size() - 1));
        
        return a.size() - res;
    }
};