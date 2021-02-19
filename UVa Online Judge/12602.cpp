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

    int a = ((s[0] - 'A') * 26 + (s[1] - 'A')) * 26 + (s[2] - 'A');
    int b = (((s[4] - '0') * 10 + (s[5] - '0')) * 10 + (s[6] - '0')) * 10 + (s[7] - '0');

    cout << (abs(a - b) <= 100 ? "nice\n" : "not nice\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}