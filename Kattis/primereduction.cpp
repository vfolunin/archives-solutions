#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getPrimeFactorSum(int n) {
    int res = 0;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            res += d;
            n /= d;
        }
    }
    if (n != 1)
        res += n;
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (n == 4)
        return 0;

    for (int i = 1; 1; i++) {
        int nextN = getPrimeFactorSum(n);
        if (n == nextN) {
            cout << n << " " << i << "\n";
            return 1;
        }
        n = nextN;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}