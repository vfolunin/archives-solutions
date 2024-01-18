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

    cout << fixed << (2 * x + y) / (x * x - x * y + 4 * y * y) + (2 * x * x - x * y + y * y) / (x + 4 * y);
}