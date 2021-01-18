#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toLower(string s) {
    for (char &c : s)
        c = tolower(c);
    return s;
}

struct Team {
    string name;
    string lowerName;
    int points = 0;
    int games = 0;
    int wins = 0;
    int ties = 0;
    int losses = 0;
    int goals = 0;
    int goalsAgainst = 0;

    bool operator < (const Team &that) const {
        if (points != that.points)
            return points > that.points;
        if (wins != that.wins)
            return wins > that.wins;
        if (goals - goalsAgainst != that.goals - that.goalsAgainst)
            return goals - goalsAgainst > that.goals - that.goalsAgainst;
        if (goals != that.goals)
            return goals > that.goals;
        if (games != that.games)
            return games < that.games;
        return lowerName < that.lowerName;
    }
};

void solve(int test) {
    string tournamentName;
    getline(cin, tournamentName);

    int teamCount;
    cin >> teamCount;
    cin.ignore();

    map<string, Team> teamMap;
    for (int i = 0; i < teamCount; i++) {
        string teamName;
        getline(cin, teamName);
        teamMap[teamName].name = teamName;
        teamMap[teamName].lowerName = toLower(teamName);
    }
    
    int gameCount;
    cin >> gameCount;
    cin.ignore();

    for (int i = 0; i < gameCount; i++) {
        string line;
        getline(cin, line);

        char teamA[100], teamB[100];
        int goalsA, goalsB;
        sscanf(line.c_str(), "%[^#]#%d@%d#%[^#]", teamA, &goalsA, &goalsB, teamB);

        teamMap[teamA].games++;
        teamMap[teamB].games++;
        teamMap[teamA].goals += goalsA;
        teamMap[teamB].goals += goalsB;
        teamMap[teamA].goalsAgainst += goalsB;
        teamMap[teamB].goalsAgainst += goalsA;
        if (goalsA > goalsB) {
            teamMap[teamA].wins++;
            teamMap[teamB].losses++;
            teamMap[teamA].points += 3;
        } else if (goalsA < goalsB) {
            teamMap[teamA].losses++;
            teamMap[teamB].wins++;
            teamMap[teamB].points += 3;
        } else {
            teamMap[teamA].ties++;
            teamMap[teamB].ties++;
            teamMap[teamA].points++;
            teamMap[teamB].points++;
        }
    }

    vector<Team> teams;
    for (auto &[_, team] : teamMap)
        teams.push_back(team);
    sort(teams.begin(), teams.end());

    if (test)
        cout << "\n";
    cout << tournamentName << "\n";
    for (int i = 0; i < teams.size(); i++) {
        Team &t = teams[i];
        cout << i + 1 << ") " << t.name << " " << t.points << "p, ";
        cout << t.games << "g (" << t.wins << "-" << t.ties << "-" << t.losses << "), ";
        cout << t.goals - t.goalsAgainst << "gd (" << t.goals << "-" << t.goalsAgainst << ")\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve(i);
}