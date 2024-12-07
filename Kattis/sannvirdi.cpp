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

    int playerCount;
    cin >> playerCount;

    vector<pair<int, string>> players(playerCount);
    for (auto &[guess, name] : players)
        cin >> name >> guess;

    sort(players.begin(), players.end());

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        auto it = lower_bound(players.begin(), players.end(), pair<int, string>(value + 1, ""));

        cout << (it == players.begin() ? ":(" : prev(it)->second) << "\n";
    }
}