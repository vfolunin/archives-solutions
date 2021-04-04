#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double a;
    cin >> a;

    cout.precision(4);
    if (cin.peek() == ' ') {
        double b;
        cin >> b;

        cout << fixed << acos(-1) * 2 * a * b << "\n";
    } else {
        cout << fixed << acos(-1) * a * a / 8 << "\n";
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