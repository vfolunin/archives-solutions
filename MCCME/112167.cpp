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

    if (y <= 2 - x * x && (x <= 0 && y >= x || x > 0 && y >= 0))
        cout << "YES";
    else
        cout << "NO";
}