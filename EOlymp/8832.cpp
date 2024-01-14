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

    double x, y;
    cin >> x >> y;

    cout << fixed << (x * x - 2 * x * y + 4 * y * y) / (x + 5) + (3 * x * x - y * y) / (y - 7);
}