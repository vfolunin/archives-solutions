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

    vector<int> x(pointCount), y(pointCount), h(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i] >> h[i];

    for (int i = 0; i < pointCount; i++) {
        int res = h[i];
        for (int j = 0; j < pointCount; j++)
            if (h[i] < h[j])
                res = min(res, (int)hypot(x[i] - x[j], y[i] - y[j]));

        cout << res << "\n";
    }
}