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

    int syllableCount, playerCount;
    cin >> syllableCount >> playerCount;

    vector<pair<int, int>> players(playerCount);
    for (int i = 0; i < playerCount; i++)
        players[i].first = i;

    for (int pos = players.size() - 1; players.size() > 1; ) {
        pos = (pos + syllableCount) % players.size();
        if (players[pos].second == 0) {
            players[pos].second = 1;
            players.insert(players.begin() + pos + 1, players[pos]);
            pos = (pos - 1 + players.size()) % players.size();
        } else if (players[pos].second == 1) {
            players[pos].second = 2;
        } else if (players[pos].second == 2) {
            players.erase(players.begin() + pos);
            pos = (pos - 1 + players.size()) % players.size();
        }
    }

    cout << players[0].first + 1;
}