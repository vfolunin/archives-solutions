#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    vector<bitset<100 * 450 + 1>> can(n / 2 + 1);
    can[0][0] = 1;

    int totalW = 0;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;

        totalW += w;

        for (int count = n / 2; count > 0; count--)
            can[count] |= can[count - 1] << w;
    }

    int l = totalW / 2;
    while (0 <= l && !can[n / 2][l])
        l--;
    int r = totalW / 2;
    while (r <= totalW && !can[n / 2][r])
        r++;

    if (test)
        cout << "\n";
    if (r > totalW || (abs(l - (totalW - l)) <= abs(r - (totalW - r))))
        cout << l << " " << totalW - l << "\n";
    else
        cout << totalW - r << " " << r << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}