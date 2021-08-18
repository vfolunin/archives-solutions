#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    long long res = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d)
            continue;

        if (d > 1) {
            res++;
            long long power = d;
            while (n / power % d == 0) {
                res++;
                power *= d;
            }
        }

        res += d * d < n;
    }

    cout << n << " " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}