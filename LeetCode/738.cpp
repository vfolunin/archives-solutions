class Solution {
    void rec(long long n, int limit, int &res) {
        if (n > limit)
            return;
        
        res = max<int>(res, n);
        
        for (int digit = n ? n % 10 : 1; digit < 10; digit++)
            rec(n * 10 + digit, limit, res);
    }
    
public:
    int monotoneIncreasingDigits(int limit) {
        int res = 0;
        rec(0, limit, res);
        return res;
    }
};