#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int itemCount, cakeCount, drinkCount;
    cin >> itemCount >> cakeCount >> drinkCount;

    double mean = 0;

    vector<int> cakes(cakeCount);
    for (int &cake : cakes) {
        cin >> cake;
        mean += cake;
    }
    sort(cakes.begin(), cakes.end());

    vector<int> drinks(drinkCount);
    for (int &drink : drinks) {
        cin >> drink;
        mean += drink;
    }
    sort(drinks.begin(), drinks.end());

    for (int i = cakeCount + drinkCount; i < itemCount; i++) {
        int item;
        cin >> item;
        mean += item;
    }

    mean /= itemCount;

    int cakeI = 0;
    for (int i = 1; i < cakeCount; i++)
        if (abs(cakes[cakeI] - mean) - 1e-9 > abs(cakes[i] - mean))
            cakeI = i;

    int drinkI = 0;
    for (int i = 1; i < drinkCount; i++)
        if (abs(drinks[drinkI] - mean) - 1e-9 > abs(drinks[i] - mean))
            drinkI = i;

    cout << "Case #" << test << ": " << cakes[cakeI] << " " << drinks[drinkI] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}