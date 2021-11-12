#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long toDec(string s, int base) {
    static string digits = "0123456789abcdef";
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
    static string digits = "0123456789abcdef";
    string res;
    while (n >= base) {
        res += digits[n % base];
        n /= base;
    }
    res += digits[n];
    reverse(res.begin(), res.end());
    return res;
}

void solve(int test) {
    string num, base;
    cin >> num >> base;

    cout << "Case " << test << ":\n";
    if (base == "dec") {
        cout << fromDec(stoi(num), 16) << " hex\n";
        cout << fromDec(stoi(num), 2) << " bin\n\n";
    } else if (base == "hex") {
        cout << toDec(num, 16) << " dec\n";
        cout << fromDec(toDec(num, 16), 2) << " bin\n\n";
    } else {
        cout << toDec(num, 2) << " dec\n";
        cout << fromDec(toDec(num, 2), 16) << " hex\n\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}