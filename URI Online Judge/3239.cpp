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

    int carCount, p;
    cin >> carCount >> p;

    vector<int> cars(carCount);
    for (int &car : cars)
        cin >> car;

    sort(cars.begin(), cars.end());

    int res = 0;
    for (int i = 0; i < carCount; i++)
        res = max(res, p * (i + 1) - cars[i]);

    cout << res + cars[0] << "\n";
}