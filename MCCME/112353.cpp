#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long toDec(string s, int base) {
    static string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    long long res = 0;
    for (char c : s)
        res = res * base + digits.find(c);
    return res;
}

string fromDec(long long n, int base, int size) {
    static string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res;
    for (int i = 0; i < size; i++) {
        res += digits[n % base];
        n /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    if (s[0] == '-') {
        cout << "-";
        s.erase(s.begin());
    }

    while (s.size() % 3)
        s = "0" + s;

    string res;
    for (int i = 0; i < s.size(); i += 3)
        res += fromDec(toDec(s.substr(i, 3), 16), 8, 4);

    while (res.size() > 1 && res[0] == '0')
        res.erase(res.begin());

    cout << res;
}