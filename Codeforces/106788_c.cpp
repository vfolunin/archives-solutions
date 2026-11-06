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

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 != x2 && y1 != y2) {
        int delta = min(abs(x1 - x2), abs(y1 - y2));
        if (x1 < x2) {
            x1 += delta;
            if (y1 < y2) {
                y1 += delta;
                cout << "NE\n";
            } else {
                y1 -= delta;
                cout << "SE\n";
            }
        } else {
            x1 -= delta;
            if (y1 < y2) {
                y1 += delta;
                cout << "NW\n";
            } else {
                y1 -= delta;
                cout << "SW\n";
            }
        }
    }

    if (x1 != x2)
        cout << (x1 < x2 ? "E" : "W");
    if (y1 != y2)
        cout << (y1 < y2 ? "N" : "S");
}