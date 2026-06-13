#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b, incPrice, xorPrice;
    cin >> a >> b >> incPrice >> xorPrice;

    if (a > b) {
        cout << (a - 1 == b && a % 2 ? xorPrice : -1) << "\n";
        return;
    }

    int res = 0;
    for (; a != b; a++)
        res += a % 2 ? incPrice : min(incPrice, xorPrice);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}