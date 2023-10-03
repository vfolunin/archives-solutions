class Solution {
public:
    vector<long long> maximumCoins(vector<int> &heroes, vector<int> &monsters, vector<int> &coins) {
        map<int, long long> totalCoins = { { 0, 0 } };
        for (int i = 0; i < monsters.size(); i++)
            totalCoins[monsters[i]] += coins[i];
        
        for (auto it = next(totalCoins.begin()); it != totalCoins.end(); it++)
            it->second += prev(it)->second;

        vector<long long> res(heroes.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = prev(totalCoins.upper_bound(heroes[i]))->second;
        return res;
    }
};