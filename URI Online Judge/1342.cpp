#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int playerCount, squareCount;
    cin >> playerCount >> squareCount;

    if (!playerCount && !squareCount)
        return 0;

    vector<int> traps(3);
    for (int &t : traps)
        cin >> t;

    int moveCount;
    cin >> moveCount;
    
    vector<int> square(playerCount), trapped(playerCount);
    int player = playerCount - 1;

    for (int i = 0; i < moveCount; i++) {
        player = (player + 1) % playerCount;
        while (trapped[player]) {
            trapped[player] = 0;
            player = (player + 1) % playerCount;
        }

        int d1, d2;
        cin >> d1 >> d2;
        square[player] += d1 + d2;
        trapped[player] |= count(traps.begin(), traps.end(), square[player]);
    }

    cout << player + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}