#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<string> a(5);
    for (string &s : a)
        cin >> s;

    sort(a.begin(), a.end());

    if (a[0] == a[4])
        cout << "poker\n";
    else if (a[0] == a[3] || a[1] == a[4])
        cout << "quads\n";
    else if (a[0] == a[2] && a[3] == a[4] || a[0] == a[1] && a[2] == a[4])
        cout << "full house\n";
    else if (a[0] == a[2] || a[1] == a[3] || a[2] == a[4])
        cout << "set\n";
    else if (a[0] == a[1] && (a[2] == a[3] || a[3] == a[4]) || a[1] == a[2] && a[3] == a[4])
        cout << "two pair\n";
    else if (a[0] == a[1] || a[1] == a[2] || a[2] == a[3] || a[3] == a[4])
        cout << "pair\n";
    else
        cout << "no pair\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}