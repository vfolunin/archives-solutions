class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        for (long long i = 999; i < n; i = i * 1000 + 999)
            res += n - i;
        return res;
    }
};