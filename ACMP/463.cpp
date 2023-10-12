#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int toDec(string &s, int base, int mod) {
    static const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int res = 0;
    for (char c : s)
        res = (res * base + DIGITS.find(c)) % mod;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int base, mod;
    string s;
    cin >> base >> mod >> s;

    cout << toDec(s, base, mod);
}