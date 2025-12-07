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
    bool completePrime(int n) {
        if (!isPrime(n))
            return 0;

        string s = to_string(n);
        for (int size = 1; size < s.size(); size++)
            if (!isPrime(stoi(s.substr(0, size))) || !isPrime(stoi(s.substr(size))))
                return 0;
        return 1;
    }
};