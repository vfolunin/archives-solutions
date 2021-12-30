#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long phi(long long n) {
    long long res = n;
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

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    cout << phi(n) / 2 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}