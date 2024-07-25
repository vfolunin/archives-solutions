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

    int x, y, radius, xc, yc;
    cin >> x >> y >> radius >> xc >> yc;

    int dx = x - xc;
    int dy = y - yc;

    if (dx * dx + dy * dy < radius * radius)
        cout << "YES";
    else if (dx * dx + dy * dy == radius * radius)
        cout << "ON BORDER";
    else
        cout << "NO";
}