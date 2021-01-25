#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcdex(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1, d = gcdex(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

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