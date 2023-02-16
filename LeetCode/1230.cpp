class Solution {
public:
    double probabilityOfHeads(vector<double> &p, int target) {
        vector<vector<double>> res(p.size() + 1, vector<double>(target + 1));
        res[0][0] = 1;

        for (int i = 1; i <= p.size(); i++) {
            res[i][0] = res[i - 1][0] * (1 - p[i - 1]);
            for (int count = 1; count <= target; count++)
                res[i][count] = res[i - 1][count - 1] * p[i - 1] + res[i - 1][count] * (1 - p[i - 1]);
        }

        return res[p.size()][target];
    }
};