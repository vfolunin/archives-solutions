#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    getline(cin, s);

    for (int i = s.size() / 2 - 1; i >= 0; i--)
        cout << s[i];
    for (int i = s.size() - 1; i >= s.size() / 2; i--)
        cout << s[i];
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}