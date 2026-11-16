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

    int playerCount, stepCount;
    cin >> playerCount >> stepCount;

    vector<string> players(playerCount);
    for (string &player : players)
        cin >> player;

    vector<int> steps(stepCount);
    for (int &step : steps)
        cin >> step;

    for (int i = 0, pi = 0; i < playerCount - 1; i++) {
        pi = (pi + steps[i % steps.size()]) % players.size();
        players.erase(players.begin() + pi);
        pi %= players.size();
    }

    cout << players[0];
}