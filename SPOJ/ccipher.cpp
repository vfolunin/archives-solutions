#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    int shift;
    cin >> s >> shift;

    for (char &c : s) {
        bool isUpper = isupper(c);
        c -= isUpper ? 'A' : 'a';
        c = (c + shift) % 26;
        c += isUpper ? 'A' : 'a';
    }

    cout << s << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}