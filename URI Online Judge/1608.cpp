#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int money, ingredientCount, cakeCount;
    cin >> money >> ingredientCount >> cakeCount;

    vector<int> ingredientPrice(ingredientCount);
    for (int &price : ingredientPrice)
        cin >> price;

    int res = 0;
    for (int i = 0; i < cakeCount; i++) {
        int ingredients;
        cin >> ingredients;

        int cakePrice = 0;
        for (int j = 0; j < ingredients; j++) {
            int ingredient, amount;
            cin >> ingredient >> amount;
            cakePrice += ingredientPrice[ingredient] * amount;
        }

        res = max(res, money / cakePrice);
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}