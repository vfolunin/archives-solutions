class Solution {
public:
    bool simpleGraphExists(vector<int> &degree) {
        sort(degree.begin(), degree.end());

        vector<long long> p(degree.begin(), degree.end());
        partial_sum(p.begin(), p.end(), p.begin());
        if (p.back() % 2)
            return 0;

        long long lSum = 0;
        for (int i = 1; i <= degree.size(); i++) {
            lSum += degree[degree.size() - i];

            int r = lower_bound(degree.begin(), degree.end(), i) - degree.begin();
            r = min<int>(r, degree.size() - i);

            long long rSum = i * (i - 1LL);
            rSum += i * (degree.size() - i - r);
            if (r)
                rSum += p[r - 1];

            if (lSum > rSum)
                return 0;
        }

        return 1;
    }
};