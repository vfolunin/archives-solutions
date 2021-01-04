#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int coinCount;
    cin >> coinCount;

    int coinValueSum = 0;
    vector<int> can(5e4 + 1);
    can[0] = 1;

    for (int i = 0; i < coinCount; i++) {
        int coinValue;
        cin >> coinValue;
        coinValueSum += coinValue;

        for (int value = 5e4; value >= coinValue; value--)
            if (can[value - coinValue])
                can[value] = 1;
    }

    int half = coinValueSum / 2;
    while (!can[half])
        half--;
    cout << coinValueSum - half - half << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}