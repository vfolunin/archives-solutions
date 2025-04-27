#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1 % mod;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int p, mod, value;
    cin >> p >> mod >> value;

    bool found = 0;
    for (int i = 0; i < mod; i++) {
        if (binPow(i, p, mod) == value) {
            cout << i << " ";
            found = 1;
        }
    }

    if (!found)
        cout << -1;
}