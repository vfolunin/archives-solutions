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
    long long splitArray(vector<int> &a) {
        vector<long long> sum(2);
        for (int i = 0; i < a.size(); i++)
            sum[isPrime(i)] += a[i];
        return abs(sum[0] - sum[1]);
    }
};