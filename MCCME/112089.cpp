#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int teamCount;
    cin >> teamCount;

    deque<int> teams(teamCount);
    int maxTeam = 0;
    for (int &team : teams) {
        cin >> team;
        maxTeam = max(maxTeam, team);
    }

    vector<pair<int, int>> rounds;
    while (teams[0] != maxTeam) {
        int teamA = teams.front();
        teams.pop_front();
        int teamB = teams.front();
        teams.pop_front();

        rounds.push_back({ teamA, teamB });
        teams.push_front(max(teamA, teamB));
        teams.push_back(min(teamA, teamB));
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        long long index;
        cin >> index;
        index--;

        if (index < rounds.size()) {
            cout << rounds[index].first << " " << rounds[index].second << "\n";
        } else {
            index = (index - rounds.size()) % (teamCount - 1) + 1;
            cout << teams[0] << " " << teams[index] << "\n";
        }
    }
}