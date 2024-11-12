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

    int ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    if (ax > bx)
        swap(ax, bx);
    if (ay > by)
        swap(ay, by);
    if (cx > dx)
        swap(cx, dx);
    if (cy > dy)
        swap(cy, dy);

    if (ay == by) {
        if (cy < ay && ay < dy) {
            ax = max(ax, cx);
            bx = min(bx, dx);

            cout << max(bx - ax, 0);
        } else {
            cout << 0;
        }
    } else {
        if (cx < ax && ax < dx) {
            ay = max(ay, cy);
            by = min(by, dy);

            cout << max(by - ay, 0);
        } else {
            cout << 0;
        }
    }
}