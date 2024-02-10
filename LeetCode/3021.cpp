class Solution {
public:
    long long flowerGame(int aLimit, int bLimit) {
        long long res = 0;
        for (int a = 1; a <= aLimit; a++) {
            if (a % 2)
                res += bLimit / 2;
            else
                res += (bLimit + 1) / 2;
        }
        return res;
    }
};