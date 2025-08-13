#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double a, b;
    char type;

    cin >> a >> b >> type;

    if (type == '+')
        cout << fixed << a / 100 * b << "\n";
    else
        cout << fixed << a / b * 100 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}