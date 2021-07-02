#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double r;
    cin >> r;

    cout.precision(10);
    cout << fixed << 9.293810046163106 * r << " ";
    cout << fixed << 10.730087938848659 * r << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}