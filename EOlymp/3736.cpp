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

    int itemCount;
    double weightLimit;
    cin >> itemCount >> weightLimit;

    vector<pair<double, double>> items(itemCount);
    for (auto &[price, weight] : items) {
        cin >> price >> weight;
        price /= weight;
    }

    sort(items.rbegin(), items.rend());

    double res = 0;
    for (auto &[price, weight] : items) {
        double delta = min(weight, weightLimit);
        weightLimit -= delta;
        res += price * delta;
    }

    cout << fixed << res;
}