#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;

    stringstream ss;
    for (int i = l; i <= r; i++)
        ss << i;

    string s = ss.str();
    cout << s;
    reverse(s.begin(), s.end());
    cout << s << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}