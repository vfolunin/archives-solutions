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

    int playerCount, winScore, recordCount;
    cin >> playerCount >> winScore >> recordCount;

    map<string, int> score;
    for (int i = 0; i < playerCount; i++) {
        string player;
        cin >> player;
        score[player];
    }

    set<string> winners;

    for (int i = 0; i < recordCount; i++) {
        string player;
        int points;
        cin >> player >> points;

        score[player] += points;
        if (score[player] >= winScore && !winners.count(player)) {
            cout << player << " wins!\n";
            winners.insert(player);
        }
    }

    if (winners.empty())
        cout << "No winner!";
}