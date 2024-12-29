#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string fromDec(long long n, int base) {
    static const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res;
    while (n >= base) {
        res += DIGITS[n % base];
        n /= base;
    }
    res += DIGITS[n];
    reverse(res.begin(), res.end());
    return res;
}

long long toDec(string s, int base) {
    static const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    long long res = 0;
    for (char c : s)
        res = res * base + DIGITS.find(c);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long value;
    cin >> value;

    string s = fromDec(value, 2), l, r;
    if (s.size() % 2) {
        l = s.substr(0, (s.size() + 1) / 2);
        r = string(l.rbegin() + 1, l.rend());
    } else {
        l = s.substr(0, s.size() / 2);
        r = string(l.rbegin(), l.rend());
    }

    long long pValue = toDec(l + r, 2);
    if (value <= pValue) {
        cout << pValue;
        return 0;
    }

    int pos = l.size() - 1;
    while (l[pos] == '1') {
        l[pos] = '0';
        pos--;
    }
    l[pos] = '1';

    if (s.size() % 2)
        r = string(l.rbegin() + 1, l.rend());
    else
        r = string(l.rbegin(), l.rend());

    cout << toDec(l + r, 2);
}