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

    if (x <= 1 && 1 - x <= y && (0 <= x || 2 * x * x <= y))
        cout << "YES";
    else
        cout << "NO";
}