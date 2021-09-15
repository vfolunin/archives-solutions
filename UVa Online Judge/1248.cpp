#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int dayCount;
    cin >> dayCount;

    vector<int> prevCost(1);

    for (int i = 0; i < dayCount; i++) {
        int price, limit, need;
        cin >> price >> limit >> need;

        vector<int> curCost;

        for (int prev = 0; prev < prevCost.size(); prev++) {
            for (int cur = max(0, need - prev); cur <= 200 && cur <= limit; cur++) {
                int i = cur - max(need - prev, 0);
                if (curCost.size() <= i)
                    curCost.resize(i + 1, 1e9);
                curCost[i] = min(curCost[i], prevCost[prev] + cur * price);
            }
        }

        prevCost.swap(curCost);
    }

    cout << *min_element(prevCost.begin(), prevCost.end()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}