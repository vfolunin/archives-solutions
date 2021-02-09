#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string decToHex(long long n) {
    static string digits = "0123456789ABCDEF";
    string res;
    while (n > 15) {
        res += digits[n % 16];
        n /= 16;
    }
    res += digits[n];
    reverse(res.begin(), res.end());
    return "0x" + res;
}

long long hexToDec(string &n) {
    static string digits = "0123456789ABCDEF";
    long long res = 0;
    for (int i = 2; i < n.size(); i++)
        res = res * 16 + digits.find(n[i]);
    return res;
}

bool solve() {
    string s;
    cin >> s;

    if (s[0] == '-')
        return 0;

    if (s.size() > 2 && s[1] == 'x')
        cout << hexToDec(s) << "\n";
    else
        cout << decToHex(stoll(s)) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}