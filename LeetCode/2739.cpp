class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res = 0;
        while (mainTank >= 5) {
            res += 50;
            mainTank -= 5;
            if (additionalTank) {
                mainTank++;
                additionalTank--;
            }
        }
        res += mainTank * 10;
        return res;
    }
};