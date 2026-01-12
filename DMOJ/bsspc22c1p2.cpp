#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    if (a % 100 != 11)
        swap(a, b);

    if (a % 100 == 11 && b % 10 == 7 && b % 100 != 17)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}