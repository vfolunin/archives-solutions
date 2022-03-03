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

    int teaCount;
    cin >> teaCount;

    vector<int> teaPrice(teaCount);
    for (int &price : teaPrice)
        cin >> price;

    int toppingCount;
    cin >> toppingCount;

    vector<int> toppingPrice(toppingCount);
    for (int &price : toppingPrice)
        cin >> price;

    int minPrice = 1e9;
    for (int i = 0; i < teaCount; i++) {
        int pairCount;
        cin >> pairCount;
        for (int j = 0; j < pairCount; j++) {
            int toppingIndex;
            cin >> toppingIndex;
            minPrice = min(minPrice, teaPrice[i] + toppingPrice[toppingIndex - 1]);
        }
    }

    int money;
    cin >> money;

    cout << max(0, money / minPrice - 1);
}