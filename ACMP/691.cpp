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

    string letters = "ABCEHKMOPTXY";
    bool ok = s.size() == 6;

    for (int i = 0; ok && i < s.size(); i++) {
        if (1 <= i && i <= 3)
            ok &= (bool)isdigit(s[i]);
        else
            ok &= letters.find(s[i]) != -1;
    }

    cout << (ok ? "Yes\n" : "No\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}