class Solution {
    vector<int> getDivisors(int n) {
        vector<int> divisors;

        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                divisors.push_back(d);
                if (d * d != n)
                    divisors.push_back(n / d);
            }
        }

        sort(divisors.begin(), divisors.end());
        return divisors;
    }
    
public:
    int kthFactor(int n, int k) {
        vector<int> divisors = getDivisors(n);
        return k <= divisors.size() ? divisors[k - 1] : -1;
    }
};