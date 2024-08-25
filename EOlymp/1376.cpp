#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long toDec(string s, int base) {
    static string digits = "0123456789ABCDEF";
    long long res = 0;
    for (char c : s) {
        int d = digits.find(c);
        if (d == -1 || d >= base)
            return -1;
        res = res * base + d;
    }
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
    int a, b;
    string sa;
    if (!(cin >> a >> b >> sa))
        return 0;

    long long x = toDec(sa, a);
    if (x == -1)
        cout << sa << " is an illegal base " << a << " number\n";
    else
        cout << sa << " base " << a << " = " << fromDec(x, b) << " base " << b << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}