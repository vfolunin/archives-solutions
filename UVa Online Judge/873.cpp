#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    double loan, rate, period;
    cin >> loan >> rate >> period;

    rate /= 1200;
    double res = rate ? loan * rate / (1 - pow(1 + rate, -period)) : loan / period;

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