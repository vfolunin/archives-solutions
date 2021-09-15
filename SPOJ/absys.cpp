#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isDigit(string &s) {
    for (char c : s)
        if (!isdigit(c))
            return 0;
    return 1;
}

void solve() {
    string a, b, c;
    cin >> a >> b >> b >> c >> c;

    if (!isDigit(a))
        cout << stoi(c) - stoi(b) << " + " << b << " = " << c << "\n";
    else if (!isDigit(b))
        cout << a << " + " << stoi(c) - stoi(a) << " = " << c << "\n";
    else
        cout << a << " + " << b << " = " << stoi(a) + stoi(b) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}