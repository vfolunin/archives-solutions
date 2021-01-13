#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, n;
    cin >> h >> n;
    
    int res = 0;
    n--;
    for (int i = 1; i < h; i++) {
        res = res * 2 + n % 2;
        n /= 2;
    }

    res += (1 << (h - 1));
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}