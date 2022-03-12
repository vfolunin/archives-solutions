#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;

    bool contains(int x, int y) {
        return x1 <= x && x <= x2 && y1 <= y && y <= y2;
    }
};

struct Circle {
    int cx, cy, r;

    bool contains(int x, int y) {
        return (cx - x) * (cx - x) + (cy - y) * (cy - y) <= r * r;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int shapeCount;
    cin >> shapeCount;

    vector<Rectangle> rectangles;
    vector<Circle> circles;

    for (int i = 0; i < shapeCount; i++) {
        string shape;
        cin >> shape;

        if (shape == "rectangle") {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            rectangles.push_back({ x1, y1, x2, y2 });
        } else {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            circles.push_back({ cx, cy, r });
        }
    }

    int pointCount;
    cin >> pointCount;

    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;

        int hitCount = 0;
        for (Rectangle &rectangle : rectangles)
            hitCount += rectangle.contains(x, y);
        for (Circle &circle : circles)
            hitCount += circle.contains(x, y);

        cout << hitCount << "\n";
    }
}