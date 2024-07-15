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

    int shopCount, fuelPrice;
    cin >> shopCount >> fuelPrice;

    int res = 1e9;
    for (int i = 0; i < shopCount; i++) {
        int mealPrice, deliveryPrice, dist;
        cin >> mealPrice >> deliveryPrice >> dist;
        res = min(res, mealPrice + deliveryPrice + dist * fuelPrice);
    }

    cout << res;
}