#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

bool solve(int test) {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    map<int, int> heights;
    for (int i = 0; i < h * w; i++) {
        int h;
        cin >> h;
        heights[h]++;
    }

    double volume;
    cin >> volume;
    volume /= 100;

    double waterLevel = heights.begin()->first;
    double flooded = (volume ? heights.begin()->second : 0);
    heights.erase(heights.begin());

    while (!heights.empty() && volume > EPS) {
        auto [h, f] = *heights.begin();
        heights.erase(heights.begin());

        double delta = min<double>(h - waterLevel, volume / flooded);
        waterLevel += delta;
        volume -= flooded * delta;

        if (volume > EPS)
            flooded += f;
    }
    if (volume > EPS)
        waterLevel += volume / flooded;

    cout << "Region " << test << "\n";
    cout.precision(2);
    cout << "Water level is " << fixed << waterLevel << " meters.\n";
    cout << fixed << flooded / (h * w) * 100 << " percent of the region is under water.\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}