class Solution {
    bool isPrime(int n) {
        if (n < 2)
            return 0;
        for (int d = 2; d * d <= n; d++)
            if (n % d == 0)
                return 0;
        return 1;
    }
    
public:
    bool isThree(int n) {
        int r = sqrt(n);
        return r * r == n && isPrime(r);
    }
};