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

    int pointCount;
    cin >> pointCount;

    vector<double> x(pointCount), y(pointCount), z(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i] >> z[i];

    for (int i = 0; i < pointCount; i++) {
        double dist = 1e9;
        for (int j = 0; j < pointCount; j++)
            if (i != j)
                dist = min(dist, hypot(x[i] - x[j], y[i] - y[j], z[i] - z[j]));

        if (dist <= 20)
            cout << "A\n";
        else if (dist <= 50)
            cout << "M\n";
        else
            cout << "B\n";
    }
}