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

    int ax1, ay2, ax2, ay1, bx1, by2, bx2, by1, x, y;
    cin >> ax1 >> ay2 >> ax2 >> ay1 >> bx1 >> by2 >> bx2 >> by1 >> x >> y;

    if (bx1 < x && x < bx2 && by1 < y && y < by2)
        cout << "SAD";
    else if (ax1 <= x && x <= ax2 && ay1 <= y && y <= ay2)
        cout << "HAPPY";
    else
        cout << "SAD";
}