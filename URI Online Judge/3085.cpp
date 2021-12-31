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

    int moveCount, maxDist, targetX, targetY;
    cin >> moveCount >> maxDist >> targetX >> targetY;

    maxDist *= maxDist;

    if (targetX * targetX + targetY * targetY > maxDist) {
        cout << "Trap 1\n";
        return 0;
    }

    int x = 0, y = 0;
    for (int i = 1; i <= moveCount; i++) {
        char move;
        cin >> move;

        if (move == 'C')
            y++;
        if (move == 'B')
            y--;
        if (move == 'D')
            x++;
        if (move == 'E')
            x--;

        int dx = x - targetX, dy = y - targetY;
        if (dx * dx + dy * dy > maxDist) {
            cout << "Trap " << i << "\n";
            return 0;
        }
    }

    if (x == targetX && y == targetY)
        cout << "Sucesso\n";
    else
        cout << "Trap " << moveCount << "\n";
}