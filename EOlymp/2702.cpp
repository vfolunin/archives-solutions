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
    for (char c : s) {
        if (DIGITS.find(c) >= base)
            return -1e18;
        res = res * base + DIGITS.find(c);
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    string a = s.substr(0, s.find('+'));
    string b = s.substr(s.find('+') + 1, s.find('=') - s.find('+') - 1);
    string c = s.substr(s.find('=') + 1);

    for (int base = 2; base <= 36; base++) {
        long long aValue = toDec(a, base);
        long long bValue = toDec(b, base);
        long long cValue = toDec(c, base);

        if (aValue != -1e18 && bValue != -1e18 && cValue != -1e18 && aValue + bValue == cValue) {
            cout << base;
            return 0;
        }
    }

    cout << -1;
}