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

    int itemCount;
    cin >> itemCount;

    vector<int> can(10001);
    can[0] = 1;
    int totalWeight = 0;

    for (int i = 0; i < itemCount; i++) {
        int weight;
        cin >> weight;

        for (int sum = can.size() - 1; sum >= weight; sum--)
            can[sum] |= can[sum - weight];

        totalWeight += weight;
    }

    cout << (totalWeight % 2 == 0 && can[totalWeight / 2] ? "YES" : "NO");
}