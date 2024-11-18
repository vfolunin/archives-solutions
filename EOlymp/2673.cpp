#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, size;
    cin >> n >> size;

    long long mod = 1;
    for (int i = 0; i < size; i++)
        mod *= 10;

    long long res = 1;
    for (int i = 0; i < n; i++) {
        res *= n;
        if (res >= mod) {
            cout << setw(size) << setfill('0') << binPow(n, n, mod);
            return 0;
        }
    }

    cout << res;
}