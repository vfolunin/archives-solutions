class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            unsigned int nextB = (a & b) * 2u;
            a ^= b;
            b = nextB;
        }
        return a;
    }
};