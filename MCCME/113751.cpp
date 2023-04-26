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

    int callPrice, freeKilometers, freeMinutes, kilometerPrice, minutePrice, tariffCount;
    cin >> callPrice >> freeKilometers >> freeMinutes >> kilometerPrice >> minutePrice >> tariffCount;

    int resCost = 1e9, resMinutes, resIndex;

    for (int i = 0; i < tariffCount; i++) {
        int kilometers, minutes;
        cin >> kilometers >> minutes;

        int cost = callPrice + max(0, kilometers - freeKilometers) * kilometerPrice + max(0, minutes - freeMinutes) * minutePrice;

        if (resCost > cost || resCost == cost && resMinutes > minutes) {
            resCost = cost;
            resMinutes = minutes;
            resIndex = i;
        }
    }

    cout << resIndex + 1 << " " << resCost;
}