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

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double a = y1 - y2, b = x2 - x1, c = x1 * y2 - x2 * y1;
    cout << fixed << a << " " << b << " " << c;
}