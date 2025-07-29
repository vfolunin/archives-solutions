#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    const long long MOD = 1e9 + 7;
    long long res = 1;

    for (int i = 0; i < 7; i++) {
        res = res * (n % MOD) % MOD;
        n--;
    }

    for (int i = 0; i < 2; i++) {
        res = res * (((n - 1) % MOD) * (n % MOD) / 2 % MOD) % MOD;
        n -= 2;
    }

    for (int i = 0; i < 6; i++) {
        res = res * (n % MOD) % MOD;
        n--;
    }

    res = res * (((n - 1) % MOD) * (n % MOD) / 2 % MOD) % MOD;
    n -= 2;

    res = res * (n % MOD) % MOD;
    n--;

    cout << res;
}