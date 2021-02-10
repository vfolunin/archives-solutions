#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Cube {
    int top = 1, north = 2, west = 3, east = 4, south = 5, bottom = 6;

    void rotate(int &a, int &b, int &c, int &d) {
        swap(a, b);
        swap(b, c);
        swap(c, d);
    }

    void rotateNorth() {
        rotate(top, south, bottom, north);
    }

    void rotateSouth() {
        rotate(top, north, bottom, south);
    }

    void rotateEast() {
        rotate(top, west, bottom, east);
    }

    void rotateWest() {
        rotate(top, east, bottom, west);
    }
};

bool solve() {
    int rotationCount;
    cin >> rotationCount;

    if (!rotationCount)
        return 0;

    Cube cube;

    for (int i = 0; i < rotationCount; i++) {
        string rotationType;
        cin >> rotationType;
        if (rotationType == "north")
            cube.rotateNorth();
        if (rotationType == "south")
            cube.rotateSouth();
        if (rotationType == "east")
            cube.rotateEast();
        if (rotationType == "west")
            cube.rotateWest();
    }

    cout << cube.top << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}