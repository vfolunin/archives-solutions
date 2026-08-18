#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("length.in", "r", stdin);
    freopen("length.out", "w", stdout);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << fixed << hypot(x1 - x2, y1 - y2);
}