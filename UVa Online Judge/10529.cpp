#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int dominoCount;
    double pl, pr;
    if (!(cin >> dominoCount >> pl >> pr))
        return 0;

    vector<double> ans(dominoCount + 1, 1e9);
    ans[0] = 0;

    for (int count = 1; count <= dominoCount; count++)
        for (int l = 0, r = count - 1; l < count; l++, r--)
            ans[count] = min(ans[count], ans[l] + ans[r] + (1 + pl * ans[l] + pr * ans[r]) / (1 - pl - pr));

    cout.precision(2);
    cout << fixed << ans[dominoCount] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}