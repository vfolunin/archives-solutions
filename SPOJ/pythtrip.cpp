#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    int c = sqrt(a * a + b * b);

    if (a * a + b * b == c * c)
        cout << "YES " << c << "\n";
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