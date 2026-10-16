#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);

    int w, h, x1, y1, x2, y2;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2)
        cout << 0 << " " << y1 << " " << w << " " << y2;
    else
        cout << x1 << " " << 0 << " " << x2 << " " << h;
}