#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> res(n + 1, { -1, -1 });
    res[0] = { 0, 0 };
    for (int i = 1; i <= n; i++) {
        if (i >= 3 && res[i - 3].first != -1)
            res[i] = { res[i - 3].first + 1, res[i - 3].second };
        else if (i >= 5 && res[i - 5].first != -1)
            res[i] = { res[i - 5].first, res[i - 5].second + 1 };
    }

    if (res[n].first != -1)
        cout << res[n].first << " " << res[n].second;
    else
        cout << "IMPOSSIBLE";
}