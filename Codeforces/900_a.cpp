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

    int lCount = 0, rCount = 0;
    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;

        lCount += x < 0;
        rCount += x > 0;
    }

    cout << (lCount <= 1 || rCount <= 1 ? "YES" : "NO");
}