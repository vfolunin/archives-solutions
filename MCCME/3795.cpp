#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double x, y;
    cin >> x >> y;

    if (y >= 2 * x + 2 && y >= -x && hypot(x + 1, y - 1) <= 2 ||
        y <= 2 * x + 2 && y <= -x && hypot(x + 1, y - 1) >= 2)
        cout << "YES";
    else
        cout << "NO";
}