#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    cin.ignore();
    
    vector<string> a(n);
    for (string &line : a)
        getline(cin, line);

    vector<string> b(n);
    for (string &line : b)
        getline(cin, line);

    set<string> changingPosition;
    for (int i = n - 1, j = n - 1; i >= 0; i--, j--) {
        while (i >= 0 && a[i] != b[j]) {
            changingPosition.insert(a[i]);
            i--;
        }
    }

    for (int i = n - 1; i >= 0; i--)
        if (changingPosition.count(b[i]))
            cout << b[i] << "\n";
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