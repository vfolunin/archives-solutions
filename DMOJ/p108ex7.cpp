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

    if (n <= 30)
        cout << "38\n";
    else if (n <= 50)
        cout << "55\n";
    else
        cout << 73 + (n - 100 + 49) / 50 * 24 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}