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
    long long power;
    cin >> size >> power;

    vector<int> thresholds(size);
    for (int &threshold : thresholds)
        cin >> threshold;

    int powerDelta;
    cin >> powerDelta;

    multiset<int> prices;
    long long res = 0;

    for (int i = 0; i < size; i++) {
        int price;
        cin >> price;

        prices.insert(price);
        while (power < thresholds[i] && !prices.empty()) {
            power += powerDelta;
            res += *prices.begin();
            prices.erase(prices.begin());
        }
        if (power < thresholds[i]) {
            cout << -1;
            return 0;
        }
    }

    cout << res;
}