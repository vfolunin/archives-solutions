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

    int carTypeCount, carLimit, carCount;
    cin >> carTypeCount >> carLimit >> carCount;

    vector<int> cars(carCount);
    for (int &car : cars) {
        cin >> car;
        car--;
    }

    vector<int> next(cars.size(), cars.size()), last(cars.size(), cars.size());
    for (int i = cars.size() - 1; i >= 0; i--) {
        next[i] = last[cars[i]];
        last[cars[i]] = i;
    }

    set<pair<int, int>> carQueue;
    vector<int> taken(carTypeCount);
    int res = 0;

    for (int i = 0; i < cars.size(); i++) {
        if (taken[cars[i]]) {
            carQueue.erase({ i, cars[i] });
        } else {
            if (carQueue.size() == carLimit) {
                taken[prev(carQueue.end())->second] = 0;
                carQueue.erase(prev(carQueue.end()));
            }
            taken[cars[i]] = 1;
            res++;
        }
        carQueue.insert({ next[i], cars[i] });
    }

    cout << res;
}