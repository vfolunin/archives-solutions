#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long toDec(string &s) {
    long long res = 0;
    for (char c : s)
        res = res * 2 + c - '0';
    return res;
}

string toBin(long long n) {
    string res;
    while (n > 1) {
        res += '0' + n % 2;
        n /= 2;
    }
    res += '0' + n % 2;
    reverse(res.begin(), res.end());
    return res;
}

bool solve(int test) {
    string a, b;
    cin >> a >> b;

    if (a == "0" && b == "0")
        return 0;

    string res = toBin(toDec(a) * toDec(b));
    int width = max(max(a.size(), b.size()), res.size());

    if (test)
        cout << "\n";
    cout << setw(width) << a << "\n";
    cout << setw(width) << b << "\n";
    cout << setw(width) << string(max(a.size(), b.size()), '-') << "\n";
    for (int i = 0; i < b.size(); i++)
        cout << setw(width - i) << (b[b.size() - 1 - i] % 2 ? a : string(a.size(), '0')) << "\n";
    cout << string(width, '-') << "\n";
    cout << setw(width) << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}