class Solution {
public:
    int accountBalanceAfterPurchase(int cost) {
        return 100 - (cost / 10 + (cost % 10 >= 5)) * 10;
    }
};