class Solution {
    const long long MOD = 1e9 + 7;
 
    long long binPow(long long x, long long p) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1) * x % MOD;
        long long r = binPow(x, p / 2);
        return r * r % MOD;
    }

    long long inv(long long x) {
        return binPow(x, MOD - 2);
    }

    long long factorial(int n) {
        long long res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i % MOD;
        return res;
    }

public:
    int numberOfSequence(int size, vector<int> &marked) {
        vector<int> lengths;
        int length = 0;

        for (int i = 0, mi = 0; i < size; i++) {
            if (mi < marked.size() && i == marked[mi]) {
                if (length)
                    lengths.push_back(length);
                length = 0;
                mi++;
            } else {
                length++;
            }
        }
        if (length)
            lengths.push_back(length);
        
        int totalLength = 0, exponent = 0;
        for (int i = 0; i < lengths.size(); i++) {
            totalLength += lengths[i];
            if ((i || !marked.front()) && (i < lengths.size() - 1 || marked.back() == size - 1))
                exponent += lengths[i] - 1;
        }

        long long res = factorial(totalLength);
        for (int length : lengths)
            res = res * inv(factorial(length)) % MOD;
        res = res * binPow(2, exponent) % MOD;
        return res;
    }
};