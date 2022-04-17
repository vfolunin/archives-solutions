class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        for (int n = x ^ y; n; n &= n - 1)
            res++;
        return res;
    }
};