#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int xorSum = 0, maxVal = 0;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        xorSum ^= val;
        maxVal = max(maxVal, val);
    }

    if (!xorSum && maxVal > 1 || xorSum && maxVal <= 1)
        cout << "Brother\n";
    else
        cout << "John\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}