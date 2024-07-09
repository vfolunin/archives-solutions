#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long num, den;
    cin >> num >> den;

    long long a = num / den, b = (num + den - 1) / den;
    long long x = 0, y = 0;

    if (a && num % a == 0) {
        x = num / a;
    } else if (b && num % b == 0) {
        y = num / b;
    } else {
        x = -num;
        y = num;
    }

    if (a * x + b * y != num)
        cout << "";

    cout << x << " " << y << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}