class Solution {
public:
    int commonFactors(int a, int b) {
        int res = 0;
        for (int d = 1; d <= a && d <= b; d++)
            res += a % d == 0 && b % d == 0;
        return res;
    }
};