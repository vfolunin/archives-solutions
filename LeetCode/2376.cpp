class Solution {
    vector<long long> precalcFactorials() {
        vector<long long> memo(11);
        memo[0] = 1;
        for (int i = 1; i < memo.size(); i++)
            memo[i] = memo[i - 1] * i;
        return memo;
    }

    long long factorial(int n) {
        static vector<long long> memo = precalcFactorials();
        return memo[n];
    }
    
    long long arrangementCount(int n, int k) {
        return factorial(n) / factorial(n - k);
    }
    
    long long rec(string &s, int i, vector<int> &used) {
        if (i == s.size())
            return 1;
        
        long long res = 0;
        
        for (int d = 0; d < s[i] - '0'; d++)
            if (!used[d] && (i || d))
                res += arrangementCount(10 - 1 - i, s.size() - 1 - i);
        
        if (!used[s[i] - '0']) {
            used[s[i] - '0'] = 1;
            res += rec(s, i + 1, used);
        }
        
        return res;
    }
    
public:
    int countSpecialNumbers(int limit) {
        string s = to_string(limit);
        long long res = 0;
        
        for (int size = 1; size < s.size(); size++)
            res += arrangementCount(10, size) - arrangementCount(9, size - 1);
        
        vector<int> used(10);
        res += rec(s, 0, used);
        
        return res;
    }
};