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

    int xc, yc, pointCount;
    cin >> xc >> yc >> pointCount;

    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;

        if ((x - xc) * (x - xc) + (y - yc) * (y - yc) <= 64) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}