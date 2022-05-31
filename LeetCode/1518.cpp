class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        while (numBottles >= numExchange) {
            int exchange = numBottles / numExchange;
            res += exchange * numExchange;
            numBottles = exchange + numBottles % numExchange;
        }
        return res + numBottles;
    }
};