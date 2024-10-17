#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long binPow(long long n, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(n, p - 1) * n;
    long long r = binPow(n, p / 2);
    return r * r;
}

void solve() {
    vector<long long> price;
    while (1) {
        long long p;
        cin >> p;
        if (!p)
            break;
        price.push_back(p);
    }

    sort(price.rbegin(), price.rend());

    long long sum = 0;
    for (int i = 0; i < price.size() && sum <= 5e6; i++)
        sum += 2 * binPow(price[i], i + 1);

    if (sum <= 5e6)
        cout << sum << "\n";
    else
        cout << "Too expensive\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}