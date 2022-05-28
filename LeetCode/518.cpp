class Solution {
public:
    int change(int amount, vector<int> &coins) {
        vector<int> ways(amount + 1);
        ways[0] = 1;
        
        for (int coin : coins)
            for (int sum = coin; sum <= amount; sum++)
                ways[sum] += ways[sum - coin];
        
        return ways[amount];
    }
};