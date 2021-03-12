#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    double income;
    cin >> income;

    static vector<double> limit = { 1.8e5, 3e5, 4e5, 3e5 };
    static vector<double> tax = { 0, 0.10, 0.15, 0.20 };

    double res = 0;
    for (int i = 0; i < 4 && income; i++) {
        double amount = min(limit[i], income);
        income -= amount;
        res += amount * tax[i];
    }
    res += income * 0.25;
    if (res)
        res = max(ceil(res), 2000.0);

    cout.precision(0);
    cout << "Case " << test << ": " << fixed << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}