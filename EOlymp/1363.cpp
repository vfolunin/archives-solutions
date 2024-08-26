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
        return x1 <= x && x < x2 && y1 <= y && y < y2;
    }

    friend istream &operator >> (istream &in, Rectangle &r) {
        in >> r.x1 >> r.y1 >> r.x2 >> r.y2;
        if (r.x1 > r.x2)
            swap(r.x1, r.x2);
        if (r.y1 > r.y2)
            swap(r.y1, r.y2);
        return in;
    }
};

int getCount(vector<Rectangle> &rectangles, int x, int y) {
    int res = 0;
    for (Rectangle &rectangle : rectangles)
        res += rectangle.contains(x, y);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int rectangleCount;
    cin >> rectangleCount;

    vector<Rectangle> rectangles(rectangleCount);
    for (Rectangle &rectangle : rectangles)
        cin >> rectangle;

    int res = 0;
    for (int x = -50; x <= 50; x++)
        for (int y = -50; y <= 50; y++)
            res = max(res, getCount(rectangles, x, y));

    cout << res;
}