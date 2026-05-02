#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w, z;
    cin >> h >> w >> z;

    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;

    cout << min(
        abs(y1 - y2) + min(x1 + x2, w - x1 + w - x2),
        abs(x1 - x2) + min(y1 + y2, h - y1 + h - y2)
    ) + z << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}