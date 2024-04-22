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

    double x;
    cin >> x;

    if (x == -3 || x == 3 || x == 6)
        cout << "NO FUNCTION";
    else if (x < -3)
        cout << 3;
    else if (x < 3)
        cout << fixed << 3 - sqrt(9 - x * x);
    else if (x < 6)
        cout << fixed << -2 * x + 9;
    else
        cout << fixed << x - 9;
}