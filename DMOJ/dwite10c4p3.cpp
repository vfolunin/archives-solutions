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

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    string s = "0" + fromDec(n, 2);
    next_permutation(s.begin(), s.end());

    cout << toDec(s, 2) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}