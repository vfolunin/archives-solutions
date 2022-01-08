#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int height;
    cin >> height;

    if (!height)
        return 0;

    int x = 1, tapCount = 0;
    for (int y = 0; y < height; y++) {
        vector<int> obstacles(3);
        for (int &obstacle : obstacles)
            cin >> obstacle;

        if (obstacles[x]) {
            int nextX = find(obstacles.begin(), obstacles.end(), 0) - obstacles.begin();
            tapCount += abs(x - nextX);
            x = nextX;
        }
    }

    cout << tapCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}