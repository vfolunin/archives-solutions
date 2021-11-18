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

    int carCount, lapCount;
    cin >> carCount >> lapCount;

    vector<pair<int, int>> cars(carCount);
    for (int i = 0; i < carCount; i++)
        cars[i].second = i;

    for (int i = 0; i < carCount; i++) {
        for (int j = 0; j < lapCount; j++) {
            int t;
            cin >> t;
            cars[i].first += t;
        }
    }

    sort(cars.begin(), cars.end());

    for (int i = 0; i < 3; i++)
        cout <<cars[i].second + 1 << "\n";
}