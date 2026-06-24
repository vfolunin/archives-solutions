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

    int opCount;
    cin >> opCount;

    int y = 0, x = 0;
    int minY = y, minX = x;
    int maxY = y, maxX = x;

    for (int i = 0; i < opCount; i++) {
        char dir;
        int delta;
        cin >> dir >> delta;

        if (dir == 'U')
            y += delta;
        else if (dir == 'R')
            x += delta;
        else if (dir == 'D')
            y -= delta;
        else
            x -= delta;

        minY = min(minY, y);
        minX = min(minX, x);
        maxY = max(maxY, y);
        maxX = max(maxX, x);
    }

    cout << maxX - minX + 40 << " " << maxY - minY + 40;
}