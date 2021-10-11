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

    if (s.size() == 3) {
        if ((s[0] == 'o') + (s[1] == 'n') + (s[2] == 'e') >= 2)
            cout << "1\n";
        else
            cout << "2\n";
    } else {
        cout << "3\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}