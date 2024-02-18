#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int cubeEdges(int side) {
    return 3 * side * (side + 1) * (side + 1);
}

int squareEdges(int side, bool first) {
    if (!side)
        return 0;
    else if (first)
        return (side + 1) * (side + 1) + 4 * side * (side + 1);
    else
        return (side + 1) * (side + 1) + 2 * side * (side + 1);
}

int lineEdges(int side, bool first) {
    if (!side)
        return 0;
    else if (first)
        return 3 + 5 * side;
    else
        return 2 + 3 * side;
}

int edges2D(int n, bool first) {
    int squareSide = sqrt(n);

    int res = squareEdges(squareSide, first);
    n -= squareSide * squareSide;

    if (n > squareSide) {
        res += lineEdges(squareSide, first);
        n -= squareSide;
    }
    res += lineEdges(n, first);

    return res;
}

int edges3D(int n) {
    int cubeSide = cbrt(n);

    int res = cubeEdges(cubeSide);
    n -= cubeSide * cubeSide * cubeSide;

    if (n > cubeSide * cubeSide) {
        res += edges2D(cubeSide * cubeSide, !cubeSide);
        n -= cubeSide * cubeSide;
    }
    if (n > cubeSide * (cubeSide + 1)) {
        res += edges2D(cubeSide * (cubeSide + 1), !cubeSide);
        n -= cubeSide * (cubeSide + 1);
    }
    res += edges2D(n, !cubeSide);

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << edges3D(n);
}