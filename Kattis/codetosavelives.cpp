#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    a.erase(remove(a.begin(), a.end(), ' '), a.end());
    b.erase(remove(b.begin(), b.end(), ' '), b.end());
    string c = to_string(stoi(a) + stoi(b));

    for (int i = 0; i < c.size(); i++)
        cout << c[i] << (i + 1 < c.size() ? " " : "\n");
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