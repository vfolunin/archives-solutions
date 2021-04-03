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

    long long lnum = 0, lden = 1, rnum = 1, rden = 0;
    for (char c : s) {
        long long num = lnum + rnum, den = lden + rden;
        if (c == 'L') {
            rnum = num;
            rden = den;
        } else {
            lnum = num;
            lden = den;
        }
    }

    cout << lnum + rnum << "/" << lden + rden << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}