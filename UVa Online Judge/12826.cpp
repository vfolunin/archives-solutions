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

bool solve(int test) {
    int y1, x1, y2, x2, y3, x3;
    if (!(cin >> y1 >> x1 >> y2 >> x2 >> y3 >> x3))
        return 0;

    cout << "Case " << test << ": ";
    if (((x1 + y1 == x2 + y2 && x1 + y1 == x3 + y3) ||
        (x1 - y1 == x2 - y2 && x1 - y1 == x3 - y3)) &&
        between(x1, x3, x2) && between(y1, y3, y2))
        cout << abs(y1 - y2) + 1;
    else
        cout << max(abs(y1 - y2), abs(x1 - x2));
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}