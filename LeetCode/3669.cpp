class Solution {
    vector<int> factorize(int n) {
        vector<int> factorization;
        
        for (long long d = 2; d * d <= n; d++) {
            while (n % d == 0) {
                factorization.push_back(d);
                n /= d;
            }
        }
        if (n != 1)
        factorization.push_back(n);
        
        return factorization;
    }

    void rec(const vector<int> &factorization, int i, int fromJ, vector<int> &cur, vector<int> &res, int &resScore) {
        if (i == factorization.size()) {
            auto [minIt, maxIt] = minmax_element(cur.begin(), cur.end());
            int curScore = *maxIt - *minIt;
            if (resScore > curScore) {
                res = cur;
                resScore = curScore;
            }
            return;
        }

        for (int j = (i && factorization[i - 1] == factorization[i] ? fromJ : 0); j < cur.size(); j++) {
            cur[j] *= factorization[i];
            rec(factorization, i + 1, j, cur, res, resScore);
            cur[j] /= factorization[i];
        }
    }

public:
    vector<int> minDifference(int n, int size) {
        vector<int> cur(size, 1);
        vector<int> res = cur;
        res.back() = n;
        int resScore = n - 1;
        rec(factorize(n), 0, 0, cur, res, resScore);
        return res;
    }
};