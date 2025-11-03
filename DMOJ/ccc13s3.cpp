#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isWinner(vector<vector<int>> &gameResult, int teamId) {
    vector<int> teamScore(gameResult.size());
    for (int a = 0; a < gameResult.size(); a++)
        for (int b = 0; b < gameResult.size(); b++)
            if (a != b)
                teamScore[a] += gameResult[a][b];

    for (int i = 0; i < teamScore.size(); i++)
        if (i != teamId && teamScore[i] >= teamScore[teamId])
            return 0;

    return 1;
}

int rec(vector<vector<int>> &gameResult, int teamId) {
    int teamA = -1, teamB = -1;
    for (int a = 0; a < gameResult.size(); a++) {
        for (int b = 0; b < gameResult.size(); b++) {
            if (a != b && gameResult[a][b] == -1) {
                teamA = a;
                teamB = b;
            }
        }
    }

    if (teamA == -1)
        return isWinner(gameResult, teamId);

    int res = 0;

    gameResult[teamA][teamB] = 3;
    gameResult[teamB][teamA] = 0;
    res += rec(gameResult, teamId);

    gameResult[teamA][teamB] = 0;
    gameResult[teamB][teamA] = 3;
    res += rec(gameResult, teamId);

    gameResult[teamA][teamB] = 1;
    gameResult[teamB][teamA] = 1;
    res += rec(gameResult, teamId);

    gameResult[teamA][teamB] = -1;
    gameResult[teamB][teamA] = -1;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int teamId, gameCount;
    cin >> teamId >> gameCount;
    teamId--;

    vector<vector<int>> gameResult(4, vector<int>(4, -1));
    for (int i = 0; i < gameCount; i++) {
        int teamA, teamB, scoreA, scoreB;
        cin >> teamA >> teamB >> scoreA >> scoreB;
        teamA--;
        teamB--;

        if (scoreA > scoreB) {
            gameResult[teamA][teamB] = 3;
            gameResult[teamB][teamA] = 0;
        } else if (scoreA < scoreB) {
            gameResult[teamA][teamB] = 0;
            gameResult[teamB][teamA] = 3;
        } else {
            gameResult[teamA][teamB] = 1;
            gameResult[teamB][teamA] = 1;
        }
    }

    cout << rec(gameResult, teamId);
}