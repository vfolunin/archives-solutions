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

    int priceCount;
    long long money;
    cin >> priceCount >> money;

    vector<long long> price(priceCount);
    for (long long &price : price)
        cin >> price;

    vector<long long> minPrice = price;
    vector<long long> maxPrice = price;
    for (int i = (int)price.size() - 2; i >= 0; i--) {
        minPrice[i] = min(minPrice[i + 1], price[i]);
        maxPrice[i] = max(maxPrice[i + 1], price[i]);
    }

    long long minRes = money, maxRes = money;
    for (int i = 0; i < price.size(); i++) {
        minRes = min(minRes, money / price[i] * minPrice[i] + money % price[i]);
        maxRes = max(maxRes, money / price[i] * maxPrice[i] + money % price[i]);
    }

    cout << minRes << " " << maxRes;
}