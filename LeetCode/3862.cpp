class Solution {
public:
    int smallestBalancedIndex(vector<int> &a) {
        long long l = accumulate(a.begin(), a.end(), 0LL), r = 1;
        for (int i = a.size() - 1; 1; i--) {
            l -= a[i];
            if (l == r)
                return i;
            r *= a[i];
            if (l < r)
                return -1;
        }
    }
};