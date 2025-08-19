#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    for (string s; cin >> s; ) {
        int d = 0;
        for (char c : s)
            d = gcd(d, c);

        cout << d << "\n";
        for (char c : s)
            cout << fromDec(c / d, 3) << " ";
        cout << "\n";
    }
}