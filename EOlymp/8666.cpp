#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s >> s;

    int open = 0;
    for (char c : s) {
        open += c == '>' ? 1 : -1;
        if (open < 0) {
            cout << "illegal\n";
            return;
        }
    }

    cout << (open ? "illegal\n" : "legal\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}