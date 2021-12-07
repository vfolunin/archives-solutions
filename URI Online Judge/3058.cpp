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
    cin >> priceCount;

    double bestPrice = 1e9;
    for (int i = 0; i < priceCount; i++) {
        double price, grams;
        cin >> price >> grams;
        bestPrice = min(bestPrice, 1000 / grams * price);
    }

    cout.precision(2);
    cout << fixed << bestPrice << "\n";
}