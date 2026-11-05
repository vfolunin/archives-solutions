#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool solve() {
    string s;
    if (!(cin >> s) || s == "0")
        return 0;

    s += ',';
    int value = 0, res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            res = gcd(res, value);
            value = 0;
        } else {
            value = value * 10 + s[i] - '0';
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}