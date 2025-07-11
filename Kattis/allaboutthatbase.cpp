#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long toDec(string s, int base) {
    if (base == 1)
        return count(s.begin(), s.end(), '1') == s.size() ? s.size() : 0;

    static const string DIGITS = "0123456789abcdefghijklmnopqrstuvwxyz";
    long long res = 0;
    for (char c : s) {
        int d = DIGITS.find(c);
        if (d >= base)
            return 0;
        res = res * base + d;
    }
    return res;
}

bool check(string &sa, char op, string &sb, string &sc, int base) {
    long long a = toDec(sa, base), b = toDec(sb, base), c = toDec(sc, base);
    if (!a || !b || !c)
        return 0;
    if (op == '+')
        return a + b == c;
    else if (op == '-')
        return a - b == c;
    else if (op == '*')
        return a * b == c;
    else
        return c * b == a;
}

void solve() {
    string sa, sb, sc;
    char op, eq;

    cin >> sa >> op >> sb >> eq >> sc;

    string res;
    for (int base = 1; base < 10; base++)
        if (check(sa, op, sb, sc, base))
            res += base + '0';
    for (int base = 10; base < 36; base++)
        if (check(sa, op, sb, sc, base))
            res += base - 10 + 'a';
    if (check(sa, op, sb, sc, 36))
        res += '0';

    cout << (!res.empty() ? res : "invalid") << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}