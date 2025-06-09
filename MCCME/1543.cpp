#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n <= 22) {
        long double res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;

        cout.precision(0);
        cout << fixed << res << " ";
        if (n <= 12)
            cout << "1\n";
        else if (n <= 20)
            cout << "2\n";
        else if (n <= 22)
            cout << "3\n";
    } else {
        cout << "0\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}