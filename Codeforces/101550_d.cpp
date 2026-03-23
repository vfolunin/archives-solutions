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

    int dayCount;
    cin >> dayCount;

    vector<int> price(dayCount);
    for (int &p : price)
        cin >> p;

    long long money = 100;

    for (int i = 1; i < dayCount; i++) {
        if (price[i - 1] >= price[i])
            continue;

        long long stockCount = min(money / price[i - 1], 100000LL);
        money -= stockCount * price[i - 1];
        money += stockCount * price[i];
    }

    cout << money;
}