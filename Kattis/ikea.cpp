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

    int friendCount, itemCount;
    cin >> friendCount >> itemCount;

    vector<pair<int, string>> items(itemCount);
    for (auto &[price, name] : items)
        cin >> name >> price;

    stable_sort(items.begin(), items.end(), [](auto &l, auto &r) {
        return l.first < r.first;
    });

    int takeCount = itemCount / friendCount;
    if (itemCount % friendCount) {
        long long sum1 = items[0].first, sum2 = 0;
        for (int i = 0; i < takeCount; i++) {
            sum1 += items[i + 1].first;
            sum2 += items[takeCount + 1 + i].first;
        }
        if (sum1 < sum2)
            takeCount++;
    }

    long long sum = 0;
    for (int i = 0; i < takeCount; i++)
        sum += items[i].first;

    cout << sum << "\n";

    sort(items.begin(), items.begin() + takeCount, [](auto &l, auto &r) {
        return l.second < r.second;
    });

    for (int i = 0; i < takeCount; i++)
        cout << items[i].second << "\n";
}