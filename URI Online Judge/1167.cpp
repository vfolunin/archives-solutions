#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int playerCount;
    cin >> playerCount;

    if (!playerCount)
        return 0;

    vector<pair<string, int>> players(playerCount);
    for (auto &[name, count] : players)
        cin >> name >> count;

    int pos = 0, count = players[pos].second;

    if (playerCount > 1) {
        if (count % 2)
            pos = (pos + count) % playerCount;
        else
            pos = ((pos - count) % playerCount + playerCount) % playerCount;

        count = players[pos].second;
        players.erase(players.begin() + pos);
        pos %= playerCount--;
    }

    while (playerCount > 1) {
        if (count % 2)
            pos = (pos + count - 1) % playerCount;
        else
            pos = ((pos - count) % playerCount + playerCount) % playerCount;

        count = players[pos].second;
        players.erase(players.begin() + pos);
        pos %= playerCount--;
    }

    cout << "Vencedor(a): " << players[0].first << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}