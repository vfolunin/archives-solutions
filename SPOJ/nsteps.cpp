#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    if (x == y)
        cout << y / 2 * 4 + y % 2 << "\n";
    else if (x == y + 2)
        cout << y / 2 * 4 + 2 + y % 2 << "\n";
    else
        cout << "No Number\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}