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

    int size;
    cin >> size;

    int res = 0;
    vector<int> prices3, prices4;

    for (int i = 0; i < size; i++) {
        double value;
        cin >> value;

        int price = value * 100 + 1e-9;

        if (price % 5 < 3)
            res += price / 5 * 5;
        else if (price % 5 == 3)
            prices3.push_back(price);
        else
            prices4.push_back(price);
    }

    while (!prices3.empty() && !prices4.empty()) {
        res += (prices3.back() + prices4.back()) / 5 * 5;
        prices3.pop_back();
        prices4.pop_back();
    }

    while (prices3.size() >= 2) {
        res += (prices3.back() + prices3[prices3.size() - 2]) / 5 * 5;
        prices3.pop_back();
        prices3.pop_back();
    }

    while (prices4.size() >= 3) {
        res += (prices4.back() + prices4[prices4.size() - 2] + prices4[prices4.size() - 3]) / 5 * 5;
        prices4.pop_back();
        prices4.pop_back();
        prices4.pop_back();
    }

    for (const vector<int> &prices : { prices3, prices4 })
        for (int price : prices)
            res += price;

    cout.precision(2);
    cout << fixed << res / 100.0;
}