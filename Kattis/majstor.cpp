#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char loser(char winner) {
    if (winner == 'R')
        return 'S';
    if (winner == 'S')
        return 'P';
    return 'R';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int roundCount, opponentCount;
    string signs;
    cin >> roundCount >> signs >> opponentCount;

    vector<map<char, int>> opponentSignCount(roundCount);
    for (int i = 0; i < opponentCount; i++) {
        string opponentSigns;
        cin >> opponentSigns;
        for (int j = 0; j < roundCount; j++)
            opponentSignCount[j][opponentSigns[j]]++;
    }

    int score = 0, maxScore = 0;
    for (int i = 0; i < roundCount; i++) {
        score += 2 * opponentSignCount[i][loser(signs[i])] + opponentSignCount[i][signs[i]];
        
        int curMaxScore = 0;
        for (char sign : string("RSP"))
            curMaxScore = max(curMaxScore, 2 * opponentSignCount[i][loser(sign)] + opponentSignCount[i][sign]);
        maxScore += curMaxScore;
    }

    cout << score << "\n" << maxScore;
}