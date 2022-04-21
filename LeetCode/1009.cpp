class Solution {
public:
    int bitwiseComplement(int n) {
        long long powerOfTwo = 2;
        while (powerOfTwo <= n)
            powerOfTwo *= 2;
        return powerOfTwo - 1 - n;
    }
};