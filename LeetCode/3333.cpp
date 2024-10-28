class Solution {
    vector<int> getParts(string &s) {
        vector<int> parts = { 1 };
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i])
                parts.back()++;
            else
                parts.push_back(1);
        }
        return parts;
    }

public:
    int possibleStringCount(string &s, int widthLimit) {
        vector<int> parts = getParts(s);

        const long long MOD = 1e9 + 7;
        long long res = 1;
        for (int partWidth : parts)
            res = res * partWidth % MOD;
        
        if (widthLimit <= parts.size())
            return res;

        vector<vector<long long>> ways(2, vector<long long>(widthLimit));
        ways[0][0] = 1;

        for (int i = 0; i < parts.size(); i++) {
            for (int width = 1; width < widthLimit; width++)
                ways[0][width] = (ways[0][width] + ways[0][width - 1]) % MOD;
            
            ways[1][0] = 0;
            for (int width = 1; width < widthLimit; width++) {
                int l = max(width - parts[i], 0), r = width - 1;
                ways[1][width] = (ways[0][r] - (l ? ways[0][l - 1] : 0) + MOD) % MOD;
            }

            ways[0].swap(ways[1]);
        }

        for (int width = 1; width < widthLimit; width++)
            res = (res - ways[0][width] + MOD) % MOD;
        return res;
    }
};