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

    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

    if (x < x1) {
        if (y < y1)
            cout << "SW";
        else if (y <= y2)
            cout << "W";
        else
            cout << "NW";
    } else if (x <= x2) {
        if (y < y1)
            cout << "S";
        else
            cout << "N";
    } else {
        if (y < y1)
            cout << "SE";
        else if (y <= y2)
            cout << "E";
        else
            cout << "NE";
    }
}