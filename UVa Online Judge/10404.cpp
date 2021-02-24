#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int stoneCount, moveCount;
    if (!(cin >> stoneCount >> moveCount))
        return 0;

    vector<int> moves(moveCount);
    for (int &move : moves)
        cin >> move;
    sort(moves.begin(), moves.end());

    vector<int> firstWins(stoneCount + 1);
    for (int i = 1; i <= stoneCount; i++) {
        for (int j = 0; j < moveCount && moves[j] <= i; j++) {
            if (!firstWins[i - moves[j]]) {
                firstWins[i] = 1;
                break;
            }
        }
    }

    cout << (firstWins[stoneCount] ? "Stan" : "Ollie") << " wins\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}