#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int bannerCount;
    cin >> bannerCount;

    vector<vector<pair<int, int>>> banners(200001);
    for (int i = 0; i < bannerCount; i++) {
        int l, size, cost;
        cin >> l >> size >> cost;
        banners[l + size - 1].push_back({ l, cost });
    }

    vector<int> profit(200001);
    for (int r = 1; r < profit.size(); r++) {
        profit[r] = profit[r - 1];
        for (auto &[l, cost] : banners[r])
            profit[r] = max(profit[r], profit[l - 1] + cost);
    }

    cout << "Case " << test << ": " << profit.back() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}