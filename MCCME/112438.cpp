#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getQuadrant(int x, int y) {
    if (!x || !y)
        return 0;
    if (x > 0 && y > 0)
        return 1;
    if (x < 0 && y > 0)
        return 2;
    if (x < 0 && y < 0)
        return 3;
    else
        return 4;
}

int getDist(const pair<int, int> &point) {
    return min(abs(point.first), abs(point.second));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<int> count(5);
    vector<pair<int, int>> point(5);

    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;

        int quadrant = getQuadrant(x, y);
        count[quadrant]++;
        if (!point[quadrant].first || getDist(point[quadrant]) > getDist({ x, y }))
            point[quadrant] = { x, y };
    }

    int quadrant = 1;
    for (int i = 2; i < count.size(); i++)
        if (count[quadrant] < count[i] || count[quadrant] == count[i] && getDist(point[quadrant]) > getDist(point[i]))
            quadrant = i;

    cout << "K = " << quadrant << "\n";
    cout << "M = " << count[quadrant] << "\n";
    cout << "A = (" << point[quadrant].first << ", " << point[quadrant].second << ")\n";
    cout << "R = " << getDist(point[quadrant]);
}