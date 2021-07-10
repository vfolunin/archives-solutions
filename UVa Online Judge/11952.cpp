#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long toDec(string &s, int base) {
    if (base == 1) {
        if (count(s.begin(), s.end(), '1') != s.size())
            return -1;
        return s.size();
    }

    long long res = 0;
    for (char c : s) {
        if (c - '0' >= base)
            return -1;
        res = res * base + c - '0';
    }
    return res;
}

void solve() {
    string a, b, c;
    cin >> a >> b >> b >> c >> c;

    int base = 1;
    while (base <= 100) {
        long long a10 = toDec(a, base);
        long long b10 = toDec(b, base);
        long long c10 = toDec(c, base);
        if (a10 + b10 == c10)
            break;
        base++;
    }

    cout << base % 101 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}