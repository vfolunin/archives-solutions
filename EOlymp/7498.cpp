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

    long long y1, x1, y2, x2, y3, x3, y4, x4, h, w;
    cin >> y1 >> x1 >> y2 >> x2 >> y3 >> x3 >> y4 >> x4 >> h >> w;

    if (y1 + h <= y2 && x1 + w <= x3 ||
        y1 + h <= y2 && x4 + w <= x2 ||
        y1 + h <= y3 && x1 + w <= x2 ||
        y4 + h <= y2 && x1 + w <= x2)
        cout << "Yes";
    else
        cout << "No";
}