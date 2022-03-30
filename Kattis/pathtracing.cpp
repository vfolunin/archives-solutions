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

    set<pair<int, int>> cells;
    pair<int, int> start = { 0, 0 }, cur = start;
    int minX = 0, minY = 0, maxX = 0, maxY = 0;

    string direction;
    while (cin >> direction) {
        if (direction == "left")
            cur.second--;
        else if (direction == "right")
            cur.second++;
        else if (direction == "up")
            cur.first--;
        else
            cur.first++;

        cells.insert(cur);
        minY = min(minY, cur.first);
        maxY = max(maxY, cur.first);
        minX = min(minX, cur.second);
        maxX = max(maxX, cur.second);
    }
    
    for (int y = minY - 1; y <= maxY + 1; y++) {
        for (int x = minX - 1; x <= maxX + 1; x++) {
            if (y < minY || y > maxY || x < minX || x > maxX)
                cout << "#";
            else if (y == start.first && x == start.second)
                cout << "S";
            else if (y == cur.first && x == cur.second)
                cout << "E";
            else if (cells.count({ y, x }))
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}