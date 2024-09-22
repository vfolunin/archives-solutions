#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long toDec(string s, int base) {
    static const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    long long res = 0;
    for (char c : s)
        res = res * base + DIGITS.find(c);
    return res;
}

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

int digitSum(string &s) {
    int res = 0;
    for (char c : s)
        res += c - '0';
    return res;
}

long long transform(long long value) {
    string s = fromDec(value, 7);
    for (char &c : s)
        c += c % 2;
    s = fromDec(digitSum(s), 7) + s;
    if (s[0] % 2)
        s = s[0] + s;
    return toDec(s, 7);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int limit;
    cin >> limit;

    int res = 1e9;
    for (int i = 1; i < 2e5; i++) {
        int value = transform(i);
        if (value > limit)
            res = min(res, value);
    }

    cout << res;
}