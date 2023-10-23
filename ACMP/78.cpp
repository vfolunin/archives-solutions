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

    int priceFull, priceEmpty;
    cin >> priceFull >> priceEmpty;

    int money = priceFull;

    for (int i = 0; i < 4; i++) {
        int emptyCount = money / priceEmpty;
        while (money - (emptyCount - 1) * priceEmpty < priceFull)
            emptyCount--;

        money = emptyCount * priceFull + (money - emptyCount * priceEmpty);
    }

    cout << money;
}