#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    int row = 0, maxRow = 0;
    for (int bit = 0; bit < 50; bit++) {
        if (n & (1LL << bit))
            row++;
        else
            row = 0;
        maxRow = max(maxRow, row);
    }

    cout << maxRow << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}