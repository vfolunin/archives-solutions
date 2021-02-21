#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<string> s(10);
    for (string &row : s)
        cin >> row;

    string text(s[0].size() - 2, 0);
    for (int i = 0; i < text.size(); i++)
        for (int bit = 0; bit < 8; bit++)
            text[i] |= ((s[bit + 1][i + 1] == '\\') << bit);

    cout << text << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}