#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iterator>
using namespace std;

void solve() {
    int producerCount, consumerCount;
    cin >> producerCount >> consumerCount;

    vector<int> producerPrice(producerCount);
    for (int &price : producerPrice)
        cin >> price;
    sort(producerPrice.begin(), producerPrice.end());

    vector<int> consumerPrice(consumerCount);
    for (int &price : consumerPrice)
        cin >> price;
    sort(consumerPrice.begin(), consumerPrice.end());

    vector<int> prices = { 0 };
    merge(producerPrice.begin(), producerPrice.end(),
          consumerPrice.begin(), consumerPrice.end(), back_inserter(prices));

    int bestPrice, bestCount = 1e9;
    for (int price : prices) {
        int count = producerPrice.end() - upper_bound(producerPrice.begin(), producerPrice.end(), price);
        count += lower_bound(consumerPrice.begin(), consumerPrice.end(), price) - consumerPrice.begin();
        if (bestCount > count || bestCount == count && bestPrice > price) {
            bestCount = count;
            bestPrice = price;
        }
    }

    cout << bestPrice << " " << bestCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}