#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int phi(int n) {
    int res = n;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            while (n % d == 0)
                n /= d;
            res -= res / d;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

int getDivisorCount(int n) {
    int res = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            res++;
            res += d * d != n;
        }
    }
    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    cout << n - phi(n) - getDivisorCount(n) + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}