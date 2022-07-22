class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int m = max({ a, b, c });
        if (m > a + b + c - m)
            return a + b + c - m;
        return (a + b + c) / 2;
    }
};