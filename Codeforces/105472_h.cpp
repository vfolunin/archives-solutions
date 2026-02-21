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

    vector<int> temperature(dayCount);
    for (int &t : temperature)
        cin >> t;

    int bestTemperature = 1e9, bestDay = -1;
    for (int i = 0; i + 2 < dayCount; i++) {
        int t = max(temperature[i], temperature[i + 2]);
        if (bestTemperature > t) {
            bestTemperature = t;
            bestDay = i;
        }
    }

    cout << bestDay + 1 << " " << bestTemperature;
}