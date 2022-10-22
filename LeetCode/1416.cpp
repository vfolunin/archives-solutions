class Solution {
public:
    int numberOfArrays(string &s, int limit) {
        const long long MOD = 1e9 + 7;
        
        vector<long long> ways(s.size() + 1);
        ways[0] = 1;
        
        for (int len = 1; len <= s.size(); len++)
            for (int part = 1; part <= 10 && part <= len; part++)
                if (s[len - part] != '0' && stoll(s.substr(len - part, part)) <= limit)
                    ways[len] = (ways[len] + ways[len - part]) % MOD;
        
        return ways.back();
    }
};