#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int targetWeight, itemCount;
    cin >> targetWeight >> itemCount;
    targetWeight /= 10;

    vector<int> can(500);
    can[0] = 1;

    for (int i = 0; i < itemCount; i++) {
        int weight;
        cin >> weight;
        weight /= 10;

        for (int sum = can.size() - 1; sum >= weight; sum--)
            can[sum] |= can[sum - weight];
    }

    int res = find(can.begin() + targetWeight, can.end(), 1) - can.begin();

    if (res < can.size())
        cout << res * 10 << "\n";
    else
        cout << "NO SOLUTION\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}