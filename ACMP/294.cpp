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

    vector<int> count(2), percent(2), price(2), remainingCount(2);
    for (int i = 0; i < count.size(); i++) {
        cin >> count[i] >> percent[i] >> price[i];
        remainingCount[i] = count[i] - count[i] / 100 * percent[i];
    }

    int pairCount = *min_element(remainingCount.begin(), remainingCount.end());
    int res = 0;
    for (int i = 0; i < count.size(); i++)
        res += (count[i] - pairCount) * price[i];

    cout << res;
}