#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int rockCount, targetRock;
    cin >> rockCount >> targetRock;

    if (!rockCount && !targetRock)
        return 0;
    targetRock--;

    if (rockCount >= 49) {
        cout << "Let me try!\n";
        return 1;
    }

    vector<vector<int>> can(2, vector<int>(rockCount));
    can[0][0] = 1;
    bool res = can[0][targetRock];

    for (int jump = 3; jump < rockCount; jump += 2) {
        can[1].assign(rockCount, 0);
        for (int i = 0; i < rockCount; i++)
            can[1][i] |= 0 <= i - jump && can[0][i - jump] || i + jump < rockCount && can[0][i + jump];
        can[0] = can[1];
        res |= can[0][targetRock];
    }

    cout << (res ? "Let me try!\n" : "Don't make fun of me!\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}