#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long toDec(string s, int base) {
    static string digits = "0123456789ABCDEF";
    long long res = 0;
    for (char c : s)
        res = res * base + digits.find(c);
    return res;
}

string fromDec(long long n, int base) {
    static string digits = "0123456789ABCDEF";
    string res;
    while (n >= base) {
        res += digits[n % base];
        n /= base;
    }
    res += digits[n];
    reverse(res.begin(), res.end());
    return res;
}

bool solve() {
    string s;
    int a, b;
    if (!(cin >> s >> a >> b))
        return 0;

    string res = fromDec(toDec(s, a), b);
    if (res.size() > 7)
        res = "ERROR";

    cout << setw(7) << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}