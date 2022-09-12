class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = n;
        for (int d = n / 2; d; d /= 2)
            res ^= d;
        return res;
    }
};