class Solution {
public:
    int distinctPrimeFactors(vector<int> &a) {
        unordered_set<int> divisors;
        for (int value : a) {
            for (int d = 2; d * d <= value; d++) {
                if (value % d == 0) {
                    divisors.insert(d);
                    while (value % d == 0)
                        value /= d;
                }
            }
            if (value != 1)
                divisors.insert(value);
        }
        return divisors.size();
    }
};