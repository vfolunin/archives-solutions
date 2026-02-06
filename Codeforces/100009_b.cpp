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

    if (n < 0)
        return 0;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            cout << "    " << d << "\n";
            n /= d;
        }
    }

    if (n != 1)
        cout << "    " << n << "\n";

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}