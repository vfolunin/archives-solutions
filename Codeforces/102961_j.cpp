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

    vector<int> coins(coinCount);
    for (int &coin : coins)
        cin >> coin;

    sort(coins.begin(), coins.end());

    long long sum = 1;
    for (int coin : coins) {
        if (sum < coin)
            break;
        sum += coin;
    }

    cout << sum;
}