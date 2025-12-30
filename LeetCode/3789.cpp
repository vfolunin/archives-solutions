class Solution {
public:
    long long minimumCost(int price1, int price2, int price12, long long need1, long long need2) {
        long long need12 = 0;
        if (price12 < price1 + price2) {
            need12 = min(need1, need2);
            need1 -= need12;
            need2 -= need12;
        }
        return min(price1, price12) * need1 + min(price2, price12) * need2 + price12 * need12;
    }
};