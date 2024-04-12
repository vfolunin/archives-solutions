#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Team {
    string name;
    int problemCount, time;

    bool operator < (const Team &that) const {
        if (problemCount != that.problemCount)
            return problemCount > that.problemCount;
        return time < that.time;
    }

    friend istream &operator >> (istream &in, Team &t) {
        return in >> t.name >> t.problemCount >> t.time;
    }

    friend ostream &operator << (ostream &out, Team &t) {
        return out << t.name << " " << t.problemCount << " " << t.time;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int teamCount;
    cin >> teamCount;

    vector<Team> teams(teamCount);
    for (Team &team : teams)
        cin >> team;

    stable_sort(teams.begin(), teams.end());

    for (Team &team : teams)
        cout << team << "\n";
}