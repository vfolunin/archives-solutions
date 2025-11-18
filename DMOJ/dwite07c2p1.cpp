#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int primeFactorCount(int n) {
    int res = 0;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            res++;
            n /= d;
        }
    }
    res += n != 1;
    return res;
}

void solve() {
    int n;
    cin >> n;

    cout << (primeFactorCount(n) == 2 ? "semiprime\n" : "not\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 5; i++)
        solve();
}