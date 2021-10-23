#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    map<char, set<int>> posA, posB;
    for (int i = 0; i < a.size(); i++) {
        if (c[i] == '_') {
            posA[a[i]].insert(i);
            posB[b[i]].insert(i);
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (!posA[c].empty() && !posB[c].empty() && posA[c] != posB[c]) {
            cout << "Y\n";
            return;
        }
    }

    cout << "N\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}