#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int playerCount, teamCount;
    cin >> playerCount >> teamCount;

    vector<pair<string, int>> players(playerCount);
    for (auto &[name, skill] : players)
        cin >> name >> skill;

    sort(players.begin(), players.end(), compare);
    
    for (int i = 0; i < teamCount; i++) {
        vector<string> team;
        for (int j = i; j < playerCount; j += teamCount)
            team.push_back(players[j].first);
        sort(team.begin(), team.end());

        cout << "Time " << i + 1 << "\n";
        for (string &name : team)
            cout << name << "\n";
        cout << "\n";
    }
}