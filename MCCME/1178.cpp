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

    int baseCost, baseAmount, extraCost, amount;
    cin >> baseCost >> baseAmount >> extraCost >> amount;

    cout << baseCost + max(amount - baseAmount, 0) * extraCost;
}