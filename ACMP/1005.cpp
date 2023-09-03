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

    vector<pair<long long, long long>> a(3);
    for (auto &[price, count] : a)
        cin >> price;
    for (auto &[price, count] : a)
        cin >> count;

    long long money;
    cin >> money;

    sort(a.begin(), a.end());

    long long res = 0;
    for (auto &[price, count] : a) {
        long long delta = count;
        if (price)
            delta = min(delta, money / price);
        res += delta;
        money -= delta * price;
    }

    cout << res;
}