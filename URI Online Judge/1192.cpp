#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b;
    char c;
    cin >> a >> c >> b;

    if (a == b)
        cout << a * b << "\n";
    else if (isupper(c))
        cout << b - a << "\n";
    else
        cout << a + b << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}