#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double a, b, c, w;
    cin >> a >> b >> c >> w;

    if (((a <= 56 && b <= 45 && c <= 25) || (a + b + c) <= 125) && w <= 7) {
        cout << "1\n";
        return 1;
    } else {
        cout << "0\n";
        return 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 0;
    for (int i = 0; i < n; i++)
        res += solve();

    cout << res << "\n";
}