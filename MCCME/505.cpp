#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getNeighborCount(vector<vector<int>> &a, int y, int x) {
    int neighborCount = -a[y][x];
    for (int ty = y - 1; ty <= y + 1; ty++)
        for (int tx = x - 1; tx <= x + 1; tx++)
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size())
                neighborCount += a[ty][tx];
    return neighborCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, iterationCount;
    cin >> size >> iterationCount;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    for (int i = 0; i < iterationCount; i++) {
        vector<vector<int>> b = a;
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                int neighborCount = getNeighborCount(a, y, x);
                if (neighborCount < 2 || neighborCount > 3)
                    b[y][x] = 0;
                else if (neighborCount == 3)
                    b[y][x] = 1;
            }
        }
        a.swap(b);
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}