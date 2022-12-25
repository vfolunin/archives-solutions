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

    int base1, base2;
    string value;
    cin >> base1 >> value >> base2;

    cout << fromDec(toDec(value, base1), base2);
}