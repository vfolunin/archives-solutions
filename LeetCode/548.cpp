class Solution {
    int getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }

public:
    bool splitArray(vector<int> &p) {
        partial_sum(p.begin(), p.end(), p.begin());

        for (int m = 0; m < p.size(); m++) {
            unordered_set<int> sums;

            for (int l = 1; l + 1 < m; l++)
                if (getSum(p, 0, l - 1) == getSum(p, l + 1, m - 1))
                    sums.insert(getSum(p, 0, l - 1));
            
            for (int r = m + 2; r + 1 < p.size(); r++)
                if (getSum(p, m + 1, r - 1) == getSum(p, r + 1, p.size() - 1) && sums.count(getSum(p, m + 1, r - 1)))
                    return 1;
        }

        return 0;
    }
};