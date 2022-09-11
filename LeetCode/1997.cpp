class Solution {
public:
    int firstDayBeenInAllRooms(vector<int> &to) {
        const long long MOD = 1e9 + 7;
        
        vector<long long> res(to.size());
        for (int i = 1; i < res.size(); i++)
            res[i] = ((res[i - 1] + 1 + res[i - 1] - res[to[i - 1]] + 1) % MOD + MOD) % MOD;
        
        return res.back();
    }
};