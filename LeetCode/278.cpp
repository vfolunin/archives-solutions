class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (isBadVersion(m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};