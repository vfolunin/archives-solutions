#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(double widthLimit, double heightLimit, vector<pair<double, double>> &rects, double scale) {
    double totalHeight = 0, rowWidth = 0, rowHeight = 0;

    for (auto [width, height] : rects) {
        width *= scale;
        height *= scale;

        if (widthLimit < width)
            return 0;

        if (rowHeight == 0 || rowHeight != height || rowWidth + width > widthLimit) {
            totalHeight += height;
            rowHeight = height;
            rowWidth = width;
        } else {
            rowWidth += width;
        }
    }

    return totalHeight <= heightLimit;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int rectCount, widthLimit, heightLimit;
    cin >> rectCount >> widthLimit >> heightLimit;

    vector<pair<double, double>> rects(rectCount);
    for (auto &[rectWidth, rectHeight] : rects)
        cin >> rectWidth >> rectHeight;

    double l = 0, r = 2e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (can(widthLimit, heightLimit, rects, m))
            l = m;
        else
            r = m;
    }

    cout << fixed << l;
}