#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int test, base;
    string s;
    cin >> test >> base >> s;

    int res = 0;
    for (char c : s)
        res = (res * base + c - '0') % (base - 1);
    
    cout << test << " " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}