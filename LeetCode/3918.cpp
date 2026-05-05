class Solution {
    int reverse(int n) {
        string s = to_string(n);
        return stoi(string(s.rbegin(), s.rend()));
    }

    bool isPrime(int n) {
        if (n < 2)
            return 0;
        
        for (long long d = 2; d * d <= n; d++)
            if (n % d == 0)
                return 0;
        
        return 1;
    }

public:
    int sumOfPrimesInRange(int n) {
        int l = n, r = reverse(n);
        if (l > r)
            swap(l, r);
        
        int res = 0;
        for (int i = l; i <= r; i++)
            if (isPrime(i))
                res += i;
        return res;
    }
};