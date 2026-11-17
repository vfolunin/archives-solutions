#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int playerCount, roundCount;
    cin >> playerCount >> roundCount;

    vector<int> players(playerCount);
    iota(players.begin(), players.end(), 1);

    rotate(players.begin(), players.begin() + players.size() - roundCount, players.end() - 1);

    for (int l = 0, r = players.size() - 1; l < r; l++, r--)
        cout << players[l] << "-" << players[r] << "\n";
}