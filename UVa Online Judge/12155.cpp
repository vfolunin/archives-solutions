#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dist(int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

bool solve(int test) {   
    int n, y1, x1, y2, x2;
    cin >> n >> y1 >> x1 >> y2 >> x2;

    if (!n)
        return 0;

    int size = n * 2 - 1;

    cout << "Case " << test << ":\n";
    for (int y = y1; y <= y2; y++) {
        int cyl = y / size * size + n - 1;
        if (cyl > y)
            cyl -= size;
        int cyr = cyl + size;

        for (int x = x1; x <= x2; x++) {
            int cxl = x / size * size + n - 1;
            if (cxl > x)
                cxl -= size;
            int cxr = cxl + size;

            int minDist = dist(y, x, cyl, cxl);
            minDist = min(minDist, dist(y, x, cyl, cxr));
            minDist = min(minDist, dist(y, x, cyr, cxl));
            minDist = min(minDist, dist(y, x, cyr, cxr));

            if (minDist < n)
                cout << (char)('a' + minDist % 26);
            else
                cout << '.';
        }
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}