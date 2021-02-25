#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int read() {
    string s;
    cin >> s;

    static string digits = "VUCD";

    int res = 0;
    for (char c : s)
        res = res * 4 + digits.find(c);
    return res;
}

void solve() {
    int a = read(), b = read();

    for (int i = 0; i < 3; i++) {
        char op;
        cin >> op;
        if (op == 'A')
            b += a;
        else if (op == 'L')
            b *= 4;
        else if (op == 'R')
            b /= 4;
    }

    int c = read();
    cout << (b == c ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << "COWCULATIONS OUTPUT\n";
    for (int i = 0; i < n; i++)
        solve();
    cout << "END OF OUTPUT\n";
}