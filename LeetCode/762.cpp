class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }
    
    bool isPrime(int n) {
        if (n <= 1)
            return 0;
        for (int d = 2; d * d <= n; d++)
            if (n % d == 0)
                return 0;
        return 1;
    }
    
public:
    int countPrimeSetBits(int l, int r) {
        int res = 0;
        for (int i = l; i <= r; i++)
            res += isPrime(ones(i));
        return res;
    }
};