class Solution {
    int count1(char c) {
        if (c == '*')
            return 9;
        else
            return c > '0';
    }
    
    int count2(const string &s) {
        map<string, int> memo;
        if (memo.count(s))
            return memo[s];
        
        int &res = memo[s];
        for (int i = 10; i <= 26; i++) {
            string si = to_string(i);
            res += (si[0] == s[0] || si[0] != '0' && s[0] == '*') && (si[1] == s[1] || si[1] != '0' && s[1] == '*');
        }
        return res;
    }
    
public:
    int numDecodings(string &s) {
        const long long MOD = 1e9 + 7;
        
        vector<long long> ways(s.size() + 1);
        ways[0] = 1;
        
        for (int len = 1; len <= s.size(); len++) {
            ways[len] += count1(s[len - 1]) * ways[len - 1];
            if (len >= 2)
                ways[len] += count2(s.substr(len - 2, 2)) * ways[len - 2];
            ways[len] %= MOD;
            
            if (!ways[len - 1] && !ways[len])
                break;
        }
        
        return ways[s.size()];
    }
};