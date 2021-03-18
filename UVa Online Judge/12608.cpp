#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int weightLimit, pointCount;
    cin >> weightLimit >> pointCount;

    vector<int> coord(pointCount), weight(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> coord[i] >> weight[i];
    coord.push_back(coord.back());
    weight.push_back(weightLimit);

    int totalLength = 0, truckWeight = 0;
    for (int i = 0; i <= pointCount; i++) {
        totalLength += coord[i] - (i ? coord[i - 1] : 0);
        if (truckWeight + weight[i] > weightLimit) {
            totalLength += 2 * coord[i];
            truckWeight = 0;
        }
        truckWeight += weight[i];
        if (truckWeight == weightLimit) {
            totalLength += 2 * coord[i];
            truckWeight = 0;
        }
    }

    cout << totalLength - 3 * coord.back() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}