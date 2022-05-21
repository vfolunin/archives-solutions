class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> minCoins(amount + 1, 1e9);
        minCoins[0] = 0;
        
        for (int coin : coins)
            for (int sum = coin; sum <= amount; sum++)
                minCoins[sum] = min(minCoins[sum], minCoins[sum - coin] + 1);
        
        return minCoins[amount] != 1e9 ? minCoins[amount] : -1;
    }
};