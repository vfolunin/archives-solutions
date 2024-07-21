#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y;
    cin >> x >> y;

    double dist = 0;
    for (int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; )
        dist += hypot(x1 - x2, y1 - y2);

    int time = round(dist * 3 / 500);

    cout << time / 60 << ":" << time % 60;
}