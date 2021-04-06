#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getSkew(double height, double width) {
    if (height < 1 || width < 1)
        return 0;
    int rows = floor((height - 1) / (sqrt(3) / 2)) + 1;
    int cols = floor(width);
    int res = rows * cols;
    if (width - cols < 0.5)
        res -= rows / 2;
    return res;
}

bool solve() {
    double height, width;
    if (!(cin >> height >> width))
        return 0;

    int grid = floor(height) * floor(width);
    int skew = max(getSkew(height, width), getSkew(width, height));

    if (grid >= skew)
        cout << grid << " grid\n";
    else
        cout << skew << " skew\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}