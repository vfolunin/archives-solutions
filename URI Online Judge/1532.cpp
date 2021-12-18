#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int dist, maxSpeed;
    cin >> dist >> maxSpeed;

    if (!dist && !maxSpeed)
        return 0;

    for (int initSpeed = 1; initSpeed <= maxSpeed; initSpeed++) {
        int coord = 0;
        for (int speed = initSpeed; speed > 0; speed--) {
            for (int i = 0; i < speed && coord <= dist; i++) {
                coord += speed;
                if (coord == dist) {
                    cout << "possivel\n";
                    return 1;
                }
            }
        }
    }

    cout << "impossivel\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}