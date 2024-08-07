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

    int radius, pointCount;
    cin >> radius >> pointCount;

    vector<int> x(pointCount), y(pointCount), price(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i] >> price[i];

    int resCost = -1, res;
    for (int i = 0; i < pointCount; i++) {
        int cost = 0;
        for (int j = 0; j < pointCount; j++) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            if (dx * dx + dy * dy <= radius * radius)
                cost += price[j];
        }
        if (resCost < cost) {
            resCost = cost;
            res = i;
        }
    }

    cout << resCost << " " << res + 1;
}