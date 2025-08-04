#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
};

bool solve() {
    int rectangleCount;
    cin >> rectangleCount;

    if (!rectangleCount)
        return 0;

    vector<Rectangle> rectangles(rectangleCount);
    for (auto &[x1, y1, x2, y2] : rectangles)
        cin >> x1 >> y1 >> x2 >> y2;

    int res = 0;
    for (int x = 0; x <= 500; x++) {
        for (int y = 0; y <= 500; y++) {
            for (auto &[x1, y1, x2, y2] : rectangles) {
                if (x1 <= x && x < x2 && y1 <= y && y < y2) {
                    res++;
                    break;
                }
            }
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}