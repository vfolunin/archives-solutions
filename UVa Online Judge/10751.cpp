#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double SQRT2 = sqrt(2);

void solve(int test) {
    int n;
    cin >> n;

    if (test)
        cout << "\n";
    cout.precision(3);
    cout << fixed << (n == 1 ? 0 : 4 * (n - 1) + SQRT2 * (n - 2) * (n - 2)) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}