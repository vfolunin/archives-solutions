class Solution {
public:
    int numberOfWays(string &s) {
        vector<int> pos;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'S')
                pos.push_back(i);
        
        if (pos.empty() || pos.size() % 2)
            return 0;
        
        const long long MOD = 1e9 + 7;
        
        long long res = 1;
        for (int i = 2; i < pos.size(); i += 2)
            res = res * (pos[i] - pos[i - 1]) % MOD;
        return res;
    }
};