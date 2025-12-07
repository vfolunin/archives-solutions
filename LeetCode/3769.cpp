class Solution {
    int binReverse(int n) {
        int res = 0;
        for (; n; n /= 2)
            res = res * 2 + n % 2;
        return res;
    }

public:
    vector<int> sortByReflection(vector<int> &a) {
        sort(a.begin(), a.end(), [&](int lhs, int rhs) {
            int lhsRev = binReverse(lhs);
            int rhsRev = binReverse(rhs);
            if (lhsRev != rhsRev)
                return lhsRev < rhsRev;
            return lhs < rhs;
        });
        return a;
    }
};