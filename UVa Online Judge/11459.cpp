#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int playerCount, edgeCount, moveCount;
    cin >> playerCount >> edgeCount >> moveCount;

    map<int, int> to;
    for (int i = 0; i < edgeCount; i++) {
        int from;
        cin >> from >> to[from];
    }

    vector<int> moves(moveCount);
    for (int &m : moves)
        cin >> m;

    vector<int> position(playerCount, 1);
    for (int i = 0; i < moveCount; i++) {
        position[i % playerCount] = min(100, position[i % playerCount] + moves[i]);
        if (to.count(position[i % playerCount]))
            position[i % playerCount] = to[position[i % playerCount]];
        if (position[i % playerCount] == 100)
            break;
    }

    for (int i = 0; i < playerCount; i++)
        cout << "Position of player " << i + 1 << " is " << position[i] << ".\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}