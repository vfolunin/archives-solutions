#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    long long whole, frac = 0;
    cin >> whole;
    if (cin.peek() == '.') {
        cin.get();
        cin >> frac;
    }

    long long num = whole, den = 1;
    while (den <= frac) {
        num *= 10;
        den *= 10;
    }
    num += frac;

    cout << den / gcd(num, den) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}