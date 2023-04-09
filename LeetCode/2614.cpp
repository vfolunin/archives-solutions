class Solution {
    bool isPrime(int n) {
        if (n < 2)
            return 0;

        for (long long d = 2; d * d <= n; d++)
            if (n % d == 0)
                return 0;

        return 1;
    }
    
public:
    int diagonalPrime(vector<vector<int>> &a) {
        int res = 0;

        for (int i = 0; i < a.size(); i++) {
            if (isPrime(a[i][i]))
                res = max(res, a[i][i]);
            if (isPrime(a[i][a.size() - 1 - i]))
                res = max(res, a[i][a.size() - 1 - i]);
        }
        
        return res;
    }
};