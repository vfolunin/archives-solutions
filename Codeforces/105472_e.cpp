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

    string rhyme;
    getline(cin, rhyme);

    int playerCount;
    cin >> playerCount;

    vector<string> players(playerCount);
    for (string &name : players)
        cin >> name;

    int syllableCount = count(rhyme.begin(), rhyme.end(), ' ') + 1;
    vector<vector<string>> teams(2);

    for (int pos = players.size() - 1, team = 0; !players.empty(); team ^= 1) {
        pos = (pos + syllableCount) % players.size();
        teams[team].push_back(players[pos]);
        players.erase(players.begin() + pos);
        if (!players.empty())
            pos = (pos - 1 + players.size()) % players.size();
    }

    for (vector<string> &team : teams) {
        cout << team.size() << "\n";
        for (string &name : team)
            cout << name << "\n";
    }
}