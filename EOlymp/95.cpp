#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double den1, value1, den2, value2;
    cin >> den1 >> value1 >> den2 >> value2;

    double num1 = den1 * value1;
    double num2 = den2 * value2;

    cout.precision(2);
    cout << fixed << (den1 + den2 ? (num1 + num2) / (den1 + den2) : 0.0) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}