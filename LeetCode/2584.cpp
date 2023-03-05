class Solution {
    unordered_map<int, int> factorize(int n) {
        unordered_map<int, int> factorization;

        for (long long d = 2; d * d <= n; d++) {
            while (n % d == 0) {
                factorization[d]++;
                n /= d;
            }
        }
        if (n != 1)
            factorization[n]++;

        return factorization;
    }

public:
    int findValidSplit(vector<int> &a) {
        vector<unordered_map<int, int>> factorization(a.size());
        for (int i = 0; i < a.size(); i++)
            factorization[i] = factorize(a[i]);
        
        unordered_map<int, int> l, r;
        for (int i = 0; i < a.size(); i++)
            for (auto &[d, count] : factorization[i])
                r[d] += count;
        int commonCount = 0;
        
        for (int i = 0; i + 1 < a.size(); i++) {
            for (auto &[d, count] : factorization[i]) {
                commonCount -= l[d] && r[d];
                l[d] += count;
                r[d] -= count;
                commonCount += l[d] && r[d];
            }
            if (!commonCount)
                return i;
        }
        
        return -1;
    }
};