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

    for (int i = 0; i < a.size(); i += 2) {
        cout << a[i];
        if (i + 1 < a.size())
            cout << a[i + 1];
        cout << b[i];
        if (i + 1 < b.size())
            cout << b[i + 1];
    }
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