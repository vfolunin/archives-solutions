#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int size, edgeCount;
    if (!(cin >> size >> edgeCount))
        return 0;

    vector<vector<int>> h(size, vector<int>(size));
    vector<vector<int>> v(size, vector<int>(size));
    for (int i = 0; i < edgeCount; i++) {
        char type;
        int y, x;
        cin >> type >> y >> x;

        if (type == 'H')
            h[y - 1][x - 1] = 1;
        else
            v[x - 1][y - 1] = 1;
    }

    for (int y = 0; y < size; y++)
        for (int x = size - 2; x >= 0; x--)
            if (h[y][x])
                h[y][x] += h[y][x + 1];

    for (int y = size - 2; y >= 0; y--)
        for (int x = 0; x < size; x++)
            if (v[y][x])
                v[y][x] += v[y + 1][x];

    if (test > 1)
        cout << "\n" << string(34, '*') << "\n\n";
    cout << "Problem #" << test << "\n\n";
    bool found = 0;
    for (int ssize = 1; ssize < size; ssize++) {
        int squareCount = 0;
        for (int y = 0; y + ssize < size; y++)
            for (int x = 0; x + ssize < size; x++)
                squareCount += h[y][x] >= ssize && h[y + ssize][x] >= ssize &&
                               v[y][x] >= ssize && v[y][x + ssize] >= ssize;
        if (squareCount) {
            cout << squareCount << " square (s) of size " << ssize << "\n";
            found = 1;
        }
    }
    if (!found)
        cout << "No completed squares can be found.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}