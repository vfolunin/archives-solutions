class Solution {
public:
    int numRollsToTarget(int diceCount, int faceCount, int targetSum) {
        const long long MOD = 1e9 + 7;
        
        vector<vector<long long>> ways(diceCount + 1, vector<long long> (targetSum + 1));
        ways[0][0] = 1;
        
        for (int dice = 1; dice <= diceCount; dice++)
            for (int face = 1; face <= faceCount; face++)
                for (int sum = dice - 1 + face; sum <= targetSum; sum++)
                    ways[dice][sum] = (ways[dice][sum] + ways[dice - 1][sum - face]) % MOD;
        
        return ways[diceCount][targetSum];
    }
};