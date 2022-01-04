#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int x1, y1, x2, y2, pointCount;
    if (!(cin >> x1 >> y2 >> x2 >> y1 >> pointCount))
        return 0;

    int res = 0;
    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;
        res += x1 <= x && x <= x2 && y1 <= y && y <= y2;
    }

    cout << "Teste " << test << "\n" << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}