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
    double x, y;
    cin >> pointCount >> x >> y;
    
    double prevX, prevY, area = 0;
    for (int i = 0; i < pointCount; i++) {
        prevX = x;
        prevY = y;
        cin >> x >> y;
        area += (x - prevX) * (y + prevY) / 2000;
    }

    cout << fixed << area;
}