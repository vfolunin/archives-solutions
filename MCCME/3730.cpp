#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

struct Rectangle {
    int xl, yl, xr, yr;

    bool operator < (const Rectangle &that) const {
        return tie(xl, yl, xr, yr) < tie(that.xl, that.yl, that.xr, that.yr);
    }

    Rectangle combine(Rectangle &that) {
        return { min(xl, that.xl), min(yl, that.yl), max(xr, that.xr), max(yr, that.yr) };
    }

    friend istream &operator >> (istream &in, Rectangle &r) {
        return in >> r.xl >> r.yl >> r.xr >> r.yr;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    vector<Rectangle> rectangles(4);
    for (Rectangle &rectangle : rectangles)
        cin >> rectangle;

    sort(rectangles.begin(), rectangles.end());

    do {
        Rectangle a = rectangles[0].combine(rectangles[1]);
        Rectangle b = rectangles[2].combine(rectangles[3]);

        if (a.yr <= b.yl) {
            cout << "Horizontal\n" << a.yr;
            return 0;
        } else if (a.xr <= b.xl) {
            cout << "Vertical\n" << a.xr;
            return 0;
        }
    } while (next_permutation(rectangles.begin(), rectangles.end()));

    cout << "Impossible";
}