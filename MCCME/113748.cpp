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

    int kilometers, minutes, callPrice, freeKilometers, freeMinutes, kilometerPrice, minutePrice;
    cin >> kilometers >> minutes >> callPrice >> freeKilometers >> freeMinutes >> kilometerPrice >> minutePrice;

    cout << callPrice + max(0, kilometers - freeKilometers) * kilometerPrice + max(0, minutes - freeMinutes) * minutePrice;
}