#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long M = 1e7;

long long readCoord() {
    long long whole, frac;
    cin >> whole;
    cin.ignore();
    cin >> frac;
    return whole * M + frac;
}

long long hypot2(long long x, long long y) {
    return x * x + y * y;
}

bool solve() {
    int pointCount;
    long long size;
    cin >> pointCount >> size;

    if (!pointCount)
        return 0;

    size *= M;
    long long size2 = size * size;

    int innerPointCount = 0;
    for (int i = 0; i < pointCount; i++) {
        long long x = readCoord(), y = readCoord();

        if (hypot2(x, y) <= size2 &&
            hypot2(size - x, y) <= size2 &&
            hypot2(x, size - y) <= size2 &&
            hypot2(size - x, size - y) <= size2)
            innerPointCount++;
    }

    size /= M;

    cout.precision(5);
    cout << fixed << size * size * innerPointCount * 1.0 / pointCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}