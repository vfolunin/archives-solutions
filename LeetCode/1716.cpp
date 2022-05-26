class Solution {
public:
    int totalMoney(int n) {
        int money = 1, res = 0;
        for (int i = 0; i < n; i++) {
            res += money;
            if (i % 7 == 6)
                money -= 5;
            else
                money++;
        }
        return res;
    }
};