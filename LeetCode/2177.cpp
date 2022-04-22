class Solution {
public:
    vector<long long> sumOfThree(long long n) {
        if (n % 3 == 0) {
            n /= 3;
            return { n - 1, n, n + 1 };
        }
        return {};
    }
};