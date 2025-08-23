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

    int pointCount;
    cin >> pointCount;

    long long res = 0, x1, y1, x2 = 0, y2 = 0;
    for (int i = 0; i < pointCount; i++) {
        char d;
        int step;
        cin >> d >> step;

        x1 = x2;
        y1 = y2;

        if (d == 'N')
            y2 += step;
        else if (d == 'E')
            x2 += step;
        else if (d == 'S')
            y2 -= step;
        else
            x2 -= step;

        res += y1 * x2 - x1 * y2;
    }

    cout << "THE AREA IS " << abs(res) / 2;
}