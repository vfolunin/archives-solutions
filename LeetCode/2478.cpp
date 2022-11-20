class Solution {
    const long long MOD = 1e9 + 7;
    
    bool isPrime(char c) {
        static string primes = "2357";
        return primes.find(c) != -1;
    }
    
    bool goodStart(string &s, int i) {
        return isPrime(s[i]) && (!i || !isPrime(s[i - 1]));
    }
    
    long long rec(string &s, int from, int partCount, int minLength, vector<vector<long long>> &memo) {
        long long &res = memo[from][partCount];
        if (res != -1)
            return res;
        
        if (from + partCount * minLength > s.size())
            return res = 0;
        
        if (partCount == 1) {
            if (isPrime(s.back()))
                return res = 0;
            
            res = 0;
            for (int i = from; i + minLength <= s.size(); i++)
                res += goodStart(s, i);
            return res;
        }
        
        res = rec(s, from + 1, partCount, minLength, memo);
        if (goodStart(s, from))
            res = (res + rec(s, from + minLength, partCount - 1, minLength, memo)) % MOD;
        return res;
    }
    
public:
    int beautifulPartitions(string &s, int partCount, int minLength) {
        vector<vector<long long>> memo(s.size(), vector<long long>(partCount + 1, -1));
        return (rec(s, 0, partCount, minLength, memo) - rec(s, 1, partCount, minLength, memo) + MOD) % MOD;
    }
};