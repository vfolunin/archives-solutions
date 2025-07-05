#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<long long> a(3);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());
    long long minValue = 1e18;
    long long maxValue = -1e18;

    do {
        long long value = (a[0] + a[1]) * a[2];
        minValue = min(minValue, value);
        maxValue = max(maxValue, value);

        value = a[0] * a[1] + a[2];
        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    } while (next_permutation(a.begin(), a.end()));

    cout << minValue << " " << maxValue << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}