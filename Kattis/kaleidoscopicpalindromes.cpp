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

bool isPalindrome(const string &s) {
    for (int l = 0, r = s.size() - 1; l < r; l++, r--)
        if (s[l] != s[r])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r, baseL = 2, baseR;
    cin >> l >> r >> baseR;

    int res = 0;
    if (baseR >= 4) {
        for (int i : { 0, 1 })
            res += l <= i && i <= r;
    } else {
        for (int i = l; i <= r; i++) {
            bool ok = 1;
            for (int base = baseL; base <= baseR && ok; base++)
                ok &= isPalindrome(fromDec(i, base));
            res += ok;
        }
    }

    cout << res;
}