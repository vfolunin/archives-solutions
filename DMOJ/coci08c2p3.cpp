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

    int ingredientCount;
    cin >> ingredientCount;

    vector<pair<long long, long long>> ingredients(ingredientCount);
    for (auto &[a, b] : ingredients)
        cin >> a >> b;

    long long res = 1e18;
    for (int mask = 1; mask < (1 << ingredientCount); mask++) {
        long long prodA = 1, sumB = 0;
        for (int bit = 0; bit < ingredientCount; bit++) {
            if (mask & (1 << bit)) {
                prodA *= ingredients[bit].first;
                sumB += ingredients[bit].second;
            }
        }
        res = min(res, abs(prodA - sumB));
    }

    cout << res;
}