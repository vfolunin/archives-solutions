#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool between(int a, int b, int c) {
    return a <= b && b <= c || a >= b && b >= c;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if (between(x1, x, x2) && between(y1, y, y2) && (y - y1) * (x2 - x1) == (x - x1) * (y2 - y1))
        cout << "YES";
    else
        cout << "NO";
}