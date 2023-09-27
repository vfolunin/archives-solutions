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

    double rubleCount = 100, dollarCount = 0, euroCount = 0;
    double maxRubleCount = 100, maxDollarCount = 0, maxEuroCount = 0;

    for (int i = 0; i < dayCount; i++) {
        double dollarPrice, euroPrice;
        cin >> dollarPrice >> euroPrice;

        rubleCount = max(dollarCount * dollarPrice, euroCount * euroPrice);
        maxRubleCount = max(maxRubleCount, rubleCount);

        dollarCount = maxRubleCount / dollarPrice;
        maxDollarCount = max(maxDollarCount, dollarCount);

        euroCount = maxRubleCount / euroPrice;
        maxEuroCount = max(maxEuroCount, euroCount);
    }

    cout.precision(2);
    cout << fixed << maxRubleCount;
}