#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double price, time;
    char type, extra;
    cin >> price >> time >> type >> extra;

    time += max(time - 40, 0.0);
    double res = time * price;

    vector<double> tax = { 0, 0.1, 0.2, 0.29, 0.35 };
    res *= 1 - tax[type - 'A'];

    if (extra == 'y')
        res -= 10;

    cout.precision(2);
    cout << fixed << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}