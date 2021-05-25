#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

long long binPow(long long n, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(n, p - 1) * n % MOD;
    long long r = binPow(n, p / 2);
    return r * r % MOD;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        long long n, p;
        cin >> n >> p;

        cout << binPow(n, p) << "\n";
    }
}