#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    if (a == b || a == c)
        cout << a << "\n";
    else if (b == c)
        cout << b << "\n";
    else
        cout << "???\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}