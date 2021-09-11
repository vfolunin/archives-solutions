#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void removeTrailingZeros(string &s) {
    while (s.size() > 1 && s.back() == '0')
        s.pop_back();
}

string mul(string s, int n) {
    reverse(s.begin(), s.end());
    for (int i = 0, overflow = 0; i < s.size() || overflow; i++) {
        if (i == s.size())
            s += '0';
        int p = (s[i] - '0') * n + overflow;
        s[i] = p % 10 + '0';
        overflow = p / 10;
    }
    removeTrailingZeros(s);
    reverse(s.begin(), s.end());
    return s;
}

string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0, overflow = 0; i < a.size() || i < b.size() || overflow; i++) {
        if (i == a.size())
            a += '0';
        if (i == b.size())
            b += '0';
        int s = (a[i] - '0') + (b[i] - '0') + overflow;
        a[i] = s % 10 + '0';
        overflow = s / 10;
    }
    removeTrailingZeros(a);
    reverse(a.begin(), a.end());
    return a;
}

string mul(string &a, string &b) {
    string res = "0";
    for (int i = b.size() - 1; i >= 0; i--)
        res = add(res, mul(a, b[i] - '0') + string(b.size() - 1 - i, '0'));
    return res;
}

bool solve() {
    string a, b;
    if (!(cin >> a >> b))
        return 0;

    string res = mul(a, b);
    int width = max(max(a.size(), b.size()), res.size());

    cout << setw(width) << a << "\n";
    cout << setw(width) << b << "\n";
        cout << setw(width) << string(max(a.size(), b.size()), '-') << "\n";
    if (a != "0" && b.size() > 1 && count(b.begin(), b.end(), '0') + 1 < b.size()) {
        for (int i = b.size() - 1; i >= 0; i--)
            if (b[i] != '0')
                cout << setw(width - (b.size() - 1 - i)) << mul(a, b[i] - '0') << "\n";
        cout << string(width, '-') << "\n";
    }
    cout << setw(width) << res << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}