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

    int stationCount, passengerCount;
    cin >> stationCount >> passengerCount;

    int res = passengerCount;

    for (int i = 1; i + 1 < stationCount; i++) {
        int passengerOut, passengerIn;
        cin >> passengerOut >> passengerIn;
        passengerCount += passengerIn - passengerOut;
        res = max(res, passengerCount);
    }

    cout << res;
}