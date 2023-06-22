#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int carCount, betCount;
    cin >> carCount >> betCount;

    vector<vector<int>> bets(betCount, vector<int>(4));
    for (vector<int> &bet : bets)
        for (int &value : bet)
            cin >> value;

    vector<int> order(carCount);
    iota(order.begin(), order.end(), 1);

    do {
        bool ok = 1;

        for (int i = 0; ok && i < betCount; i++) {
            int res = 0;

            int pa = find(order.begin(), order.end(), bets[i][0]) - order.begin();
            int pb = find(order.begin(), order.end(), bets[i][1]) - order.begin();
            res += pa < pb;

            pa = find(order.begin(), order.end(), bets[i][2]) - order.begin();
            pb = find(order.begin(), order.end(), bets[i][3]) - order.begin();
            res += pa < pb;

            ok &= res == 1;
        }

        if (ok) {
            for (int value : order)
                cout << value << " ";
            return 0;
        }
    } while (next_permutation(order.begin(), order.end()));

    cout << 0;
}