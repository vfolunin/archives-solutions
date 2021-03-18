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

    int problemCount, teamCount, subCount;
    cin >> problemCount >> teamCount >> subCount;

    vector<int> lastTime(problemCount, -1);
    vector<int> lastTeam(problemCount, -1);
    vector<vector<int>> solved(teamCount, vector<int>(problemCount));

    for (int i = 0; i < subCount; i++) {
        int time, team;
        string problem, verdict;
        cin >> time >> team >> problem >> verdict;

        if (verdict == "Yes" && !solved[team - 1][problem[0] - 'A']) {
            lastTime[problem[0] - 'A'] = time;
            lastTeam[problem[0] - 'A'] = team;
            solved[team - 1][problem[0] - 'A'] = 1;
        }
    }

    for (int i = 0; i < problemCount; i++) {
        cout << (char)(i + 'A') << " ";
        if (lastTime[i] != -1)
            cout << lastTime[i] << " " << lastTeam[i] << "\n";
        else
            cout << "- -\n";
    }
}