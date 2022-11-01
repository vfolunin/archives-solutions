class Solution {
public:
    int minDays(int n) {
        static unordered_map<int, int> memo;
        if (memo.count(n))
            return memo[n];
        int &res = memo[n];
        
        if (n <= 1)
            return res = n;
        
        res = min(minDays(n / 2) + 1 + n % 2, minDays(n / 3) + 1 + n % 3);
        return res;
    }
};