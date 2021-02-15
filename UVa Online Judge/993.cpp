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

    if (n < 10) {
        cout << n << "\n";
        return;
    }
    
    string res;
    for (int d = 9; d > 1; d--) {
        while (n % d == 0) {
            res += '0' + d;
            n /= d;
        }
    }

    if (n != 1) {
        cout << "-1\n";
    } else {
        reverse(res.begin(), res.end());
        cout << res << "\n";
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