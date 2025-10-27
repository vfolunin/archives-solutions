#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    string digits, digit = "22233344455566677778889999";
    for (char c : s) {
        if (isdigit(c))
            digits += c;
        else if (isupper(c))
            digits += digit[c - 'A'];
    }

    cout << digits.substr(0, 3) << "-" << digits.substr(3, 3) << "-" << digits.substr(6, 4) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}