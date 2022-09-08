class Solution {
    bool isPrime(long long n) {
        if (n < 2)
            return 0;
        for (long long d = 2; d * d <= n; d++)
            if (n % d == 0)
                return 0;
        return 1;
    }
    
    void tryCandidate(const string &s, int n, int &res) {
        long long value = stoll(s);
        if (n <= value && (res == -1 || res > value) && isPrime(value))
            res = value;
    }
    
public:
    int primePalindrome(int n) {
        int res = -1;
        
        for (int center = 0; center < 10; center++)
            tryCandidate(string(1, center + '0'), n, res);
        
        for (int left = 1; left < 1e4; left++) {
            string leftS = to_string(left);
            string rightS = leftS;
            reverse(rightS.begin(), rightS.end());
            
            tryCandidate(leftS + rightS, n, res);
            
            for (int center = 0; center < 10; center++)
                tryCandidate(leftS + string(1, center + '0') + rightS, n, res);
        }
        
        return res;
    }
};