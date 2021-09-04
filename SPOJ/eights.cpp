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
    n--;

    if (n > 3)
        cout << n / 4;

    static vector<int> mods = { 192, 442, 692, 942 };
    cout << mods[n % 4] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}