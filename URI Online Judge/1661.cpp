#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> amount(n);
    for (int &a : amount)
        cin >> a;

    long long res = 0;
    for (int buyer = 0, seller = 0; buyer < n; buyer++) {
        while (amount[buyer] > 0) {
            while (amount[seller] >= 0)
                seller++;
            int delta = min(amount[buyer], -amount[seller]);
            amount[buyer] -= delta;
            amount[seller] += delta;
            res += 1LL * delta * abs(buyer - seller);
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}