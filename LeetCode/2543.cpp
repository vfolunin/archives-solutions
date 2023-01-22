class Solution {
public:
    bool isReachable(int a, int b) {
        int d = gcd(a, b);
        return !(d & (d - 1));
    }
};