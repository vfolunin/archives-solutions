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
    for (char c : s)
        res = res * base + DIGITS.find(c);
    return res;
}

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

void solve() {
    int baseA, baseB, baseC;
    string sa, sb, op;
    cin >> baseA >> sa >> baseB >> sb >> op >> baseC;

    long long a = toDec(sa, baseA);
    long long b = toDec(sb, baseB);
    
    long long c;
    if (op == "+")
        c = a + b;
    else if (op == "-")
        c = a - b;
    else if (op == "*")
        c = a * b;
    else
        c = a / b;

    cout << fromDec(c, baseC) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}