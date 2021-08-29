#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int price, coinCount;
    cin >> price >> coinCount;

    vector<int> coins(coinCount);
    for (int i = 0; i < coinCount; i++) {
        cin >> coins[i];
        if (i)
            coins[i] += coins[i - 1];
    }

    vector<int> can(price + 1);
    can[0] = 0;

    for (int coin : coins)
        for (int sum = coin; sum <= price; sum++)
            can[sum] |= can[sum - coin];

    if (test)
        cout << "\n";
    cout << (can[price] ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}