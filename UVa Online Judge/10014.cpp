#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    double first, last;
    cin >> n >> first >> last;

    vector<double> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    double res = first * n + last;
    for (int i = 1; i <= n; i++)
        res -= 2 * i * c[n - i];
    res /= n + 1;

    if (test)
        cout << "\n";
    cout.precision(2);
    cout << fixed << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}