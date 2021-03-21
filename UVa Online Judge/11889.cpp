#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<int, int> factorize(int n) {
    map<int, int> factors;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factors[d]++;
            n /= d;
        }
    }
    if (n != 1)
        factors[n]++;
    return factors;
}

void solve() {
    int a, lcm;
    cin >> a >> lcm;

    map<int, int> aF = factorize(a);
    map<int, int> lcmF = factorize(lcm);

    int b = 1;
    for (auto &[d, count] : lcmF) {
        if (count > aF[d]) {
            for (int i = 0; i < count; i++)
                b *= d;
        }
    }

    for (auto &[d, count] : aF) {
        if (count > lcmF[d]) {
            cout << "NO SOLUTION\n";
            return;
        }
    }

    cout << b << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        solve();
}