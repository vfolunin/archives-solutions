class Solution {
public:
    int equalPairs(vector<vector<int>> &a) {
        int res = 0;
        for (int ri = 0; ri < a.size(); ri++) {
            for (int ci = 0; ci < a.size(); ci++) {
                bool equal = 1;
                for (int i = 0; i < a.size() && equal; i++)
                    equal &= a[ri][i] == a[i][ci];
                res += equal;
            }
        }
        return res;
    }
};