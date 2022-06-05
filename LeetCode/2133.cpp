class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int k5 = 0, k10 = 0;
        for (int bill : bills) {
            if (bill == 5) {
                k5++;
            } else if (bill == 10) {
                if (k5 < 1)
                    return 0;
                k5--;
                k10++;
            } else {
                if (k5 < 3 && (k5 < 1 || k10 < 1))
                    return 0;
                if (k5 >= 1 && k10 >= 1) {
                    k5--;
                    k10--;
                } else {
                    k5 -= 3;
                }
            }
        }
        return 1;
    }
};