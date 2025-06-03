#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int sum, limitA, limitB, limitC;
    cin >> sum >> limitA >> limitB >> limitC;

    long long res = 0;
    for (int a = 0; a <= limitA && a <= sum; a++)
        for (int b = 0; b <= limitB && a + b <= sum; b++)
            res += min(sum - a - b, limitC) + 1;

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