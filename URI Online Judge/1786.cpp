#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    int b1 = 0, b2 = 0;
    for (int i = 0; i < s.size(); i++) {
        b1 += (i + 1) * (s[i] - '0');
        b2 += (9 - i) * (s[i] - '0');
    }

    cout << s.substr(0, 3) << ".";
    cout << s.substr(3, 3) << ".";
    cout << s.substr(6, 3) << "-";
    cout << b1 % 11 % 10 << b2 % 11 % 10 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}