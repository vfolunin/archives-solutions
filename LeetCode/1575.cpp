class Solution {
public:
    int countRoutes(vector<int> &pos, int start, int finish, int maxFuel) {
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> ways(maxFuel + 1, vector<long long>(pos.size()));
        ways[0][start] = 1;
        
        for (int fuel = 1; fuel <= maxFuel; fuel++)
            for (int i = 0; i < pos.size(); i++)
                for (int j = 0; j < pos.size(); j++)
                    if (i != j && fuel >= abs(pos[i] - pos[j])) 
                        ways[fuel][i] = (ways[fuel][i] + ways[fuel - abs(pos[i] - pos[j])][j]) % MOD;

        long long res = 0;
        for (int fuel = 0; fuel <= maxFuel; fuel++)
            res = (res + ways[fuel][finish]) % MOD;
        return res;
    }
};