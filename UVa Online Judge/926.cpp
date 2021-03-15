#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, startX, startY, finishX, finishY;
    cin >> size >> startX >> startY >> finishX >> finishY;
    size++;

    vector<vector<bool>> workUp(size, vector<bool>(size));
    vector<vector<bool>> workRight(size, vector<bool>(size));

    int workCount;
    cin >> workCount;

    for (int i = 0; i < workCount; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;

        if (c == 'N')
            workUp[x][y] = 1;
        if (c == 'S')
            workUp[x][y - 1] = 1;
        if (c == 'E')
            workRight[x][y] = 1;
        if (c == 'W')
            workRight[x - 1][y] = 1;
    }

    vector<vector<long long>> paths(size, vector<long long>(size));
    paths[startX][startY] = 1;

    for (int x = startX; x <= finishX; x++) {
        for (int y = startY; y <= finishY; y++) {
            if (x + 1 < size && !workRight[x][y])
                paths[x + 1][y] += paths[x][y];
            if (y + 1 < size && !workUp[x][y])
                paths[x][y + 1] += paths[x][y];
        }
    }

    cout << paths[finishX][finishY] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}