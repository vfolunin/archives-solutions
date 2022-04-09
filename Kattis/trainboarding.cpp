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

    int carCount, carSize, passengerCount;
    cin >> carCount >> carSize >> passengerCount;

    vector<int> cars(carCount);
    int maxDist = 0;

    for (int i = 0; i < passengerCount; i++) {
        int x;
        cin >> x;

        int carIndex = min(x / carSize, carCount - 1);
        maxDist = max(maxDist, abs(carIndex * carSize + carSize / 2 - x));
        cars[carIndex]++;
    }

    cout << maxDist << "\n";
    cout << *max_element(cars.begin(), cars.end());
}