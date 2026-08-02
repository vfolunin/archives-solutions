class Solution {
public:
    long long maxPairStrength(vector<int> &values) {
        long long res = 0;
        for (int a : values)
            for (int b : values)
                res = max(res, 1LL * a * b / gcd(a, b) / gcd(a, b));
        return res;
    }
};