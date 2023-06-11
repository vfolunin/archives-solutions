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

    int recordCount;
    cin >> recordCount;

    map<int, int> bestPrice, bestPriceCount;

    for (int i = 0; i < recordCount; i++) {
        string buf;
        int type, price;
        cin >> buf >> buf >> type >> price;

        if (!bestPrice.count(type) || bestPrice[type] > price) {
            bestPrice[type] = price;
            bestPriceCount[type] = 1;
        } else if (bestPrice[type] == price) {
            bestPriceCount[type]++;
        }
    }

    for (int type : { 92, 95, 98 })
        cout << bestPriceCount[type] << " ";
}