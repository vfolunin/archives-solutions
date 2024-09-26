#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Box {
    double xl, yl, xr, yr;
    string type;

    bool has(double x, double y) {
        return xl <= x && x <= xr && yl <= y && y <= yr;
    }

    friend istream &operator >> (istream &in, Box &box) {
        return in >> box.xl >> box.yl >> box.xr >> box.yr >> box.type;
    }
};

bool solve() {
    int boxCount;
    cin >> boxCount;

    if (!boxCount)
        return 0;

    vector<Box> boxes(boxCount);
    for (Box &box : boxes)
        cin >> box;

    int pointCount;
    cin >> pointCount;

    for (int i = 0; i < pointCount; i++) {
        double x, y;
        string type;
        cin >> x >> y >> type;

        cout << type << " ";

        bool found = 0;
        for (Box &box : boxes) {
            if (box.has(x, y)) {
                cout << (box.type == type ? "correct" : box.type) << "\n";
                found = 1;
                break;
            }
        }

        if (!found)
            cout << "floor\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}