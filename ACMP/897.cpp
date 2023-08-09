#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

map<int, int> factorize(int n) {
    map<int, int> factorization;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n != 1)
        factorization[n]++;

    return factorization;
}

void solve() {
    int n;
    cin >> n;

    int commonP = 0;
    for (auto &[d, p] : factorize(n))
        commonP = gcd(commonP, p);

    cout << (commonP > 1 ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}