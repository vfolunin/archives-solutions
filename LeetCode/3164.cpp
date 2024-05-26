class Solution {
    vector<int> getDivisors(int n) {
        vector<int> divisors;
        
        for (long long d = 1; d * d <= n; d++) {
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
    long long numberOfPairs(vector<int> &a, vector<int> &b, int k) {
        unordered_map<int, int> count;
        for (int value : b)
            count[value]++;

        long long res = 0;
        for (int value : a)
            if (value % k == 0)
                for (int d : getDivisors(value / k))
                    res += count[d];
        return res;
    }
};