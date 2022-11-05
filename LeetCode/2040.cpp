class Solution {
    int countLessEqual(vector<long long> &a, long long value) {
        return upper_bound(a.begin(), a.end(), value) - a.begin();
    }

    int countGreaterEqual(vector<long long> &a, long long value) {
        return a.end() - lower_bound(a.begin(), a.end(), value);
    }

    long long countLess(vector<long long> &a, vector<long long> &b, long long p) {
        long long res = 0;
        for (int a : a) {
            if (p < 0) {
                if (a < 0)
                    res += countGreaterEqual(b, p / a + 1);
                else if (a > 0)
                    res += countLessEqual(b, p / a - 1);
            } else if (p == 0) {
                if (a < 0)
                    res += countGreaterEqual(b, 1);
                else if (a > 0)
                    res += countLessEqual(b, -1);
            } else {
                if (a < 0)
                    res += countGreaterEqual(b, (p - 1) / a);
                else if (a == 0)
                    res += b.size();
                else
                    res += countLessEqual(b, (p - 1) / a);
            }
        }
        return res;
    }

public:
    long long kthSmallestProduct(vector<int> &aInt, vector<int> &bInt, long long k) {
        vector<long long> a(aInt.begin(), aInt.end());
        vector<long long> b(bInt.begin(), bInt.end());
        if (a.size() > b.size())
            swap(a, b);
        
        long long l = -1e10, r = 1e10 + 1;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (countLess(a, b, m) < k)
                l = m;
            else
                r = m;
        }
        return l;
    }
};