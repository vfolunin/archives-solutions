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

    int size, x, y, w, h;
    cin >> size >> x >> y >> w >> h;

    long long xCount = 0;
    if (x % size) {
        xCount = 1;
        w -= size - x % size;
    }
    xCount += (w + size - 1) / size;

    long long yCount = 0;
    if (y % size) {
        yCount = 1;
        h -= size - y % size;
    }
    yCount += (h + size - 1) / size;

    cout << xCount * yCount;
}