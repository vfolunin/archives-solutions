#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Rectangle {
    int yl = 1e9, xl = 1e9, yr = -1e9, xr = -1e9;

    void add(int y, int x) {
        yl = min(yl, y);
        xl = min(xl, x);
        yr = max(yr, y);
        xr = max(xr, x);
    }

    friend ostream &operator << (ostream &out, Rectangle &r) {
        return out << r.xl << " " << r.yl << " " << r.xr + 1 << " " << r.yr + 1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, rectangleCount;
    cin >> h >> w >> rectangleCount;

    vector<Rectangle> rectangles(rectangleCount);
    int definedIndex = -1;

    for (int y = h - 1; y >= 0; y--) {
        for (int x = 0; x < w; x++) {
            int index;
            cin >> index;

            if (index) {
                rectangles[index - 1].add(y, x);
                definedIndex = index - 1;
            }
        }
    }

    for (auto &rectangle : rectangles)
        cout << (rectangle.xl != 1e9 ? rectangle : rectangles[definedIndex]) << "\n";
}