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

    int count, price50, price4;
    cin >> count >> price50 >> price4;

    int resCost = 1e9, res50, res4;
    for (int count50 = 0, count4 = count; count50 <= count; count50++, count4--) {
        int cur50 = (count50 + 49) / 50;
        int cur4 = (count4 + 3) / 4;
        int curCost = cur50 * price50 + cur4 * price4;

        if (resCost > curCost) {
            resCost = curCost;
            res50 = cur50;
            res4 = cur4;
        }
    }

    cout << res50 << " " << res4;
}