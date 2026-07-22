#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int itemCount;
    cin >> itemCount;

    vector<int> canMake(1e5 + 1);
    canMake[0] = 1;

    for (int i = 0; i < itemCount; i++) {
        int value;
        cin >> value;

        for (int sum = canMake.size() - 1; sum >= value; sum--)
            canMake[sum] |= canMake[sum - value];
    }

    int res = 0;
    for (int sum = 0; sum < canMake.size(); sum++)
        if (canMake[sum])
            res += sum;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}