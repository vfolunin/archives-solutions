#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string fromDec(long long n, int base) {
    static string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res;
    while (n >= base) {
        res += digits[n % base];
        n /= base;
    }
    res += digits[n];
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value, base;
    cin >> value >> base;

    if (value < 0) {
        cout << "-";
        value = -value;
    }

    cout << fromDec(value, base);
}