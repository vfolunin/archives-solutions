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

    int pointCount, targetCount;
    cin >> pointCount >> targetCount;

    vector<double> dists;
    for (int i = 0; i < pointCount; i++) {
        double x, y, z;
        cin >> x >> y >> z;

        dists.push_back(hypot(x, y, z));
    }

    nth_element(dists.begin(), dists.begin() + targetCount - 1, dists.end());

    cout << fixed << dists[targetCount - 1];
}