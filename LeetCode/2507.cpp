class Solution {
    vector<int> factorize(int n) {
        vector<int> factorization;
        
        for (long long d = 2; d * d <= n; d++) {
            while (n % d == 0) {
                factorization.push_back(d);
                n /= d;
            }
        }
        if (n != 1)
        factorization.push_back(n);
        
        return factorization;
    }

public:
    int smallestValue(int n) {
        unordered_set<int> seen;
        int res = n;

        while (!seen.count(n)) {
            seen.insert(n);
            int nextN = 0;
            for (int p : factorize(n))
                nextN += p;
            n = nextN;
            res = min(res, n);
        }

        return res;
    }
};