class Solution {
    inline static const long long MOD = 1e9 + 7;
    
public:
    int numWays(string s) {
        vector<int> onesPos;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
                onesPos.push_back(i);
        
        if (onesPos.size() % 3)
            return 0;
        
        if (onesPos.empty())
            return (s.size() * (s.size() - 1) / 2 - s.size() + 1) % MOD;
        
        int k = onesPos.size() / 3;
        long long a = onesPos[k] - onesPos[k - 1];
        long long b = onesPos[2 * k] - onesPos[2 * k - 1];
        
        return a * b % MOD;
    }
};