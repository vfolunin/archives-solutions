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

    int coinCount;
    cin >> coinCount;

    vector<int> can(2000);
    can[0] = 1;

    for (int i = 0; i < coinCount; i++) {
        int coin;
        cin >> coin;

        for (int sum = coin; sum < can.size(); sum++)
            can[sum] |= can[sum - coin];
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int sum;
        cin >> sum;

        cout << can[sum] << " ";
    }
}