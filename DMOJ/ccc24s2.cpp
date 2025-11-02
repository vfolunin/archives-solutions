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

    for (int i = 1; i < s.size(); i++) {
        if ((count[s[i - 1] - 'a'] == 1) == (count[s[i] - 'a'] == 1)) {
            cout << "F\n";
            return;
        }
    }

    cout << "T\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; i++)
        solve();
}