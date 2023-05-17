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

    double x, y;
    cin >> x >> y;

    if (-acos(-1) <= x && x <= acos(-1) && -1 <= y && y <= 0 && y <= cos(x))
        cout << "YES";
    else
        cout << "NO";
}