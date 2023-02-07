class Solution {
    void rec(int n, int from, vector<int> &factors, vector<vector<int>> &res) {
        if (n == 1) {
            if (factors.size() >= 2)
                res.push_back(factors);
            return;
        }

        for (int i = from; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                rec(n / i, i, factors, res);
                factors.pop_back();
            }
        }

        factors.push_back(n);
        rec(1, n, factors, res);
        factors.pop_back();
    }

public:
    vector<vector<int>> getFactors(int n) {
        vector<int> factors;
        vector<vector<int>> res;
        rec(n, 2, factors, res);
        return res;
    }
};