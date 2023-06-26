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

    int discountCount;
    cin >> discountCount;

    vector<pair<int, int>> discounts(discountCount);
    for (auto &[percent, limit] : discounts)
        cin >> percent >> limit;

    int itemCount;
    cin >> itemCount;

    int cost = 0;
    for (int i = 0; i < itemCount; i++) {
        int price;
        cin >> price;

        int discountPercent = 0;
        for (auto &[percent, limit] : discounts)
            if (cost > limit)
                discountPercent = percent;

        cost += price * (100 - discountPercent) / 100;
    }

    cout << cost;
}