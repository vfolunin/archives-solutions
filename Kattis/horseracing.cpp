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

    int horseCount, distance;
    cin >> horseCount >> distance;

    double resTime = 1e9;
    int resIndex;
    for (int i = 0; i < horseCount; i++) {
        double speed, stamina;
        cin >> speed >> stamina;

        double dist = distance, delta = min(dist, stamina);
        double time = delta / speed;
        dist -= delta;
        time += dist / (speed / 2);

        if (resTime > time) {
            resTime = time;
            resIndex = i;
        }
    }

    cout << resIndex;
}