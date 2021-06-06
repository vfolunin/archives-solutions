#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int factorialPower(int f, int p) {
    int res = 0;
    while (f) {
        f /= p;
        res += f;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    cout << factorialPower(n, 5) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}