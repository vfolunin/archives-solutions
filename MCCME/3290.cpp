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

    int k1, k2, money, price;
    cin >> k1 >> k2 >> money >> price;

    vector<int> res(money + 1);
    for (int sum = 1; sum < res.size(); sum++) {
        res[sum] = res[sum - 1];
        if (sum >= price)
            res[sum] = max(res[sum], res[sum - price] + 1);
        if (sum >= price * k1)
            res[sum] = max(res[sum], res[sum - price * k1] + k1 + 1);
        if (sum >= price * (k2 - 1))
            res[sum] = max(res[sum], res[sum - price * (k2 - 1)] + k2);
    }

    cout << res.back();
}