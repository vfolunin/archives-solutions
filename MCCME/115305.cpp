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

    int dayCount;
    cin >> dayCount;

    vector<int> price(dayCount);
    for (int &value : price)
        cin >> value;

    vector<vector<int>> cost(dayCount + 1, vector<int>(dayCount + 1, 1e9));
    vector<vector<int>> prevCoupons(dayCount + 1, vector<int>(dayCount + 1));

    cost[0][0] = 0;

    for (int day = 1; day <= dayCount; day++) {
        for (int coupons = 0; coupons <= day; coupons++) {
            int pCoupons = coupons - (price[day - 1] > 100);
            if (pCoupons >= 0 && cost[day][coupons] > cost[day - 1][pCoupons] + price[day - 1]) {
                cost[day][coupons] = cost[day - 1][pCoupons] + price[day - 1];
                prevCoupons[day][coupons] = pCoupons;
            }
            if (coupons < dayCount && cost[day][coupons] > cost[day - 1][coupons + 1]) {
                cost[day][coupons] = cost[day - 1][coupons + 1];
                prevCoupons[day][coupons] = coupons + 1;
            }
        }
    }

    int bestCoupons = -1;
    for (int coupons = 0; coupons <= dayCount; coupons++) {
        if (cost[dayCount][coupons] == -1)
            continue;
        if (bestCoupons == -1 || cost[dayCount][bestCoupons] >= cost[dayCount][coupons])
            bestCoupons = coupons;
    }

    vector<int> usageDays;
    int coupons = bestCoupons;
    for (int day = dayCount; day; day--) {
        if (prevCoupons[day][coupons] > coupons)
            usageDays.push_back(day);
        coupons = prevCoupons[day][coupons];
    }
    reverse(usageDays.begin(), usageDays.end());

    cout << cost[dayCount][bestCoupons] << "\n";
    cout << bestCoupons << " " << usageDays.size();
}