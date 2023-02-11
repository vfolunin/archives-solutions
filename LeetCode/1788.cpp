class Solution {
    int getSum(vector<int> &p, int l, int r) {
        if (l > r)
            return 0;
        return p[r] - (l ? p[l - 1] : 0);
    }

public:
    int maximumBeauty(vector<int> &a) {
        vector<int> p(a.size());
        for (int i = 0; i < a.size(); i++)
            if (a[i] > 0)
                p[i] = a[i];
        partial_sum(p.begin(), p.end(), p.begin());

        unordered_map<int, int> first;
        int res = -2e9;
        for (int i = 0; i < a.size(); i++) {
            if (first.count(a[i]))
                res = max(res, 2 * a[i] + getSum(p, first[a[i]] + 1, i - 1));
            else
                first[a[i]] = i;
        }
        return res;
    }
};