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

    int x1, x2, y1, y2, pointCount;
    cin >> x1 >> x2 >> y1 >> y2 >> pointCount;

    int res = 0;
    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;

        res += x1 <= x && x <= x2 && y1 <= y && y <= y2;
    }

    cout << res;
}