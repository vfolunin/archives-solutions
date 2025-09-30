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

    int res = 1;
    for (int i = 0; i + 1 < s.size(); i++)
        res += s.substr(i, 2) == "<3";

    for (int i = 0; i < res; i++)
        cout << "<3 ";
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