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

    int circleCount;
    cin >> circleCount;

    vector<pair<int, int>> circles(circleCount);
    for (auto &[radius, points] : circles) {
        cin >> radius >> points;
        radius *= radius;
    }

    int pointCount;
    cin >> pointCount;

    int score = 0;
    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;

        int dist = x * x + y * y;

        int j = 0;
        while (j < circles.size() && circles[j].first < dist)
            j++;
        if (j < circles.size())
            score += circles[j].second;
    }

    cout << score;
}