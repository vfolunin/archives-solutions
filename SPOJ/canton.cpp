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

    cout << "TERM " << n;

    int row = 1;
    while (n > row) {
        n -= row;
        row++;
    }

    if (row % 2)
        n = row - n + 1;

    cout << " IS " << n << "/" << row - n + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}