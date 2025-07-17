#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string fromDec(long long n, int base) {
    static const string DIGITS = "0123456789abcdefghijklmnopqrstuvwxyz";
    string res;
    while (n >= base) {
        res += DIGITS[n % base];
        n /= base;
    }
    res += DIGITS[n];
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int base = 2; base <= 16; base++) {
        string s = fromDec(n, base);
        if (s.size() > 2 && s.substr(s.size() - 2) == "00") {
            cout << base << " " << s << "\n";
            return 0;
        }
    }

    cout << "impossible";
}