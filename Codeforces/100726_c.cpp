#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int d, n;
    cin >> d >> n;

    map<int, int> seen = { { 0, 1 } };
    int sum = 0;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum = (sum + x) % d;
        res += seen[sum];
        seen[sum]++;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}