class Solution {
public:
    int findComplement(int num) {
        long long powerOfTwo = 1;
        while (powerOfTwo <= num)
            powerOfTwo *= 2;
        return powerOfTwo - 1 - num;
    }
};