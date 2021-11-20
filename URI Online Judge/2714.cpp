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

    bool ok = s.size() == 20;
    ok &= s.substr(0, 2) == "RA";
    for (int i = 2; i < s.size(); i++)
        ok &= (bool)isdigit(s[i]);

    int p = 2;
    while (p < s.size() && s[p] == '0')
        p++;
    ok &= p < s.size();
    
    if (ok)
        cout << s.substr(p) << "\n";
    else
        cout << "INVALID DATA\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}