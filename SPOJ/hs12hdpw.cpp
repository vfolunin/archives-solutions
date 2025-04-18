#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> indexes;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        int a = 0, b = 0;
        for (int j = 0; j < s.size(); j++) {
            a |= s[j] & (1 << j);
            b |= (s[j] >> ((j + 3) % s.size()) & 1) << j;
        }

        indexes.push_back(a);
        indexes.push_back(b);
    }

    string s;
    cin >> s;

    for (int i : indexes)
        cout << s[i];
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