#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long toDec(string s, int base) {
    static string digits = "0123456789ABCDEF";
    long long res = 0;
    for (char c : s) {
        int d = digits.find(c);
        if (d == -1 || d >= base)
            return 0;
        res = res * base + d;
    }
    return res;
}

void solve() {
    int test;
    string s;
    cin >> test >> s;

    cout << test << " ";
    cout << toDec(s, 8) << " ";
    cout << toDec(s, 10) << " ";
    cout << toDec(s, 16) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}