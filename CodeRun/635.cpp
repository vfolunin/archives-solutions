#include <unordered_map>
using namespace std;

const long long MOD = 1e9 - 7538;

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1 % mod;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

long long solution(long long n) {
    static unordered_map<long long, long long> memo;
    if (memo.count(n))
        return memo[n];
    long long &res = memo[n];

    if (!n)
        return res = 1;

    return res = (binPow(solution(n / 2), solution(n / 3), MOD) + 5 * solution(n / 4) + n) % MOD;
}
