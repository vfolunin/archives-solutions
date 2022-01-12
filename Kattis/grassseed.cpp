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

    double price;
    int lawnCount;
    cin >> price >> lawnCount;

    double totalCost = 0;
    for (int i = 0; i < lawnCount; i++) {
        double h, w;
        cin >> h >> w;
        totalCost += price * h * w;
    }

    cout << fixed << totalCost;
}