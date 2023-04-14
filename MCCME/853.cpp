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

    vector<double> x(pointCount), y(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i];

    for (int a = 0; a < pointCount; a++) {
        for (int b = a + 1; b < pointCount; b++) {
            for (int c = b + 1; c < pointCount; c++) {
                double ab = hypot(x[a] - x[b], y[a] - y[b]);
                double ac = hypot(x[a] - x[c], y[a] - y[c]);
                double bc = hypot(x[b] - x[c], y[b] - y[c]);

                if (ab < ac + bc && ac < ab + bc && bc < ab + ac) {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }

    cout << "NO";
}