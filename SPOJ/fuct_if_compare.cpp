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

    if (a < b)
        cout << a << " is smaller than " << b << "\n";
    else if (a > b)
        cout << a << " is greater than " << b << "\n";
    else
        cout << "n is equal m: " << a << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}