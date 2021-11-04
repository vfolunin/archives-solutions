#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int dayCount, charge;
    if (!(cin >> dayCount >> charge))
        return 0;

    vector<int> price(dayCount);
    for (int &p : price)
        cin >> p;

    vector<vector<int>> profit(dayCount, vector<int>(2));

    profit[0][0] = 0;
    profit[0][1] = -price[0] - charge;

    for (int day = 1; day < dayCount; day++) {
        profit[day][0] = max(profit[day - 1][0], profit[day - 1][1] + price[day]);
        profit[day][1] = max(profit[day - 1][1], profit[day - 1][0] - price[day] - charge);
    }

    cout << profit[dayCount - 1][0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}