#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long toDec(const string &s, int base) {
    static const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    long long res = 0;
    for (char c : s) {
        if (int digit = DIGITS.find(c); digit < base)
            res = res * base + digit;
        else
            return -1;
    }
    return res;
}

long long parse(const string &s) {
    int sep = s.find(':');
    return toDec(s.substr(sep + 1), stoi(s.substr(0, sep)));
}

void solve() {
    string s;
    cin >> s;

    int sep = s.find('=');
    long long a = parse(s.substr(0, sep));
    long long b = parse(s.substr(sep + 1));

    cout << (a != -1 && a == b ? "+" : "-");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}