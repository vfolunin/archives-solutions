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

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;

    bool found = 0;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] == 1) {
            cout << (char)(i + 'a');
            found = 1;
        }
    }

    if (!found)
        cout << -1;

    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}