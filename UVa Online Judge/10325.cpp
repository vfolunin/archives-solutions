#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

bool solve() {
    long long n, divisorCount;
    if (!(cin >> n >> divisorCount))
        return 0;

    vector<long long> divisors(divisorCount);
    for (long long &d : divisors)
        cin >> d;

    long long res = n;
    for (int mask = 1; mask < (1 << divisorCount); mask++) {
        long long m = 0, parity = 0;
        for (int bit = 0; bit < divisorCount; bit++) {
            if (mask & (1 << bit)) {
                m = m ? lcm(m, divisors[bit]) : divisors[bit];
                parity ^= 1;
            }
        }
        res += n / m * (parity ? -1 : 1);
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}