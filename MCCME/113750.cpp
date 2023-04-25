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

    int kilometers, minutes, tariffCount;
    cin >> kilometers >> minutes >> tariffCount;

    vector<string> resNames;
    int resCost = 1e9;

    for (int i = 0; i < tariffCount; i++) {
        string name;
        int callPrice, freeKilometers, freeMinutes, kilometerPrice, minutePrice;
        cin >> name >> callPrice >> freeKilometers >> freeMinutes >> kilometerPrice >> minutePrice;
 
        int cost = callPrice + max(0, kilometers - freeKilometers) * kilometerPrice + max(0, minutes - freeMinutes) * minutePrice;

        if (resCost > cost) {
            resNames = { name };
            resCost = cost;
        } else if (resCost == cost) {
            resNames.push_back(name);
        }
    }

    for (string &name : resNames)
        cout << name << " ";
    cout << resCost;
}