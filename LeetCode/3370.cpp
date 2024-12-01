class Solution {
public:
    int smallestNumber(int n) {
        int res = 2;
        while (res - 1 < n)
            res *= 2;
        return res - 1;
    }
};