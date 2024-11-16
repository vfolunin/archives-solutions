#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<double> values(3);
    for (double &value : values)
        cin >> value;

    sort(values.begin(), values.end());
    double height = values[0], bisector = values[1], median = values[2];

    if (height == median) {
        cout << 0;
        return 0;
    }

    if (height == bisector || bisector == median) {
        cout << -1;
        return 0;
    }

    double sideAL = 0, sideAR = 1e9;
    for (int i = 0; i < 200; i++) {
        double sideA = (sideAL + sideAR) / 2;
        double delta = sqrt(median * median - height * height);
        double sideB = hypot(sideA / 2 + delta, height);
        double sideC = hypot(sideA / 2 - delta, height);
        double delta2 = (delta - sideA / 2) + sideA * sideC / (sideB + sideC);

        if (hypot(delta2, height) < bisector)
            sideAR = sideA;
        else
            sideAL = sideA;
    }

    cout << fixed << height * sideAL / 2;
}