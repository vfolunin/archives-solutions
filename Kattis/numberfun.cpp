#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c || a - b == c || b - a == c ||
        a * b == c || c * b == a || c * a == b)
        cout << "Possible\n";
    else
        cout << "Impossible\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}