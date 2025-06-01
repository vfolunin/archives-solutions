#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int itemCount, weightLimit;
    cin >> itemCount >> weightLimit;

    vector<int> weight(itemCount);
    for (int i = 0; i < itemCount; i++) {
        int count;
        cin >> count;

        for (int j = 0; j < count; j++) {
            int value;
            cin >> value;

            weight[i] += value;
        }
    }

    vector<int> can(weightLimit + 1, 0);
    can[0] = 1;

    for (int i = 0; i < itemCount; i++)
        for (int sum = weightLimit; sum >= weight[i]; sum--)
            can[sum] |= can[sum - weight[i]];

    int res = weightLimit;
    while (!can[res])
        res--;

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