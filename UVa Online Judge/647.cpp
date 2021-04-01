#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readMoves() {
    vector<int> moves;
    while (1) {
        int m;
        cin >> m;

        if (!m)
            break;

        moves.push_back(m);
    }
    return moves;
}

bool solve(vector<int> &moves) {
    int playerCount;
    cin >> playerCount;

    if (!playerCount)
        return 0;

    map<int, int> chute;
    while (1) {
        int from, to;
        cin >> from >> to;

        if (!from && !to)
            break;

        chute[from] = to;
    }

    set<int> lose, extra;
    while (1) {
        int from;
        cin >> from;

        if (!from)
            break;

        if (from < 0)
            lose.insert(-from);
        else
            extra.insert(from);
    }

    vector<int> pos(playerCount, 0);
    vector<int> loss(playerCount, 0);

    for (int p = 0, i = 0; 1; p = (p + 1) % playerCount, i++) {
        if (loss[p]) {
            loss[p] = 0;
            continue;
        }

        if (pos[p] + moves[i] <= 100)
            pos[p] += moves[i];

        if (chute.count(pos[p]))
            pos[p] = chute[pos[p]];

        if (pos[p] == 100) {
            cout << p + 1 << "\n";
            return 1;
        }

        if (lose.count(pos[p]))
            loss[p] = 1;

        if (extra.count(pos[p]))
            p--;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> moves = readMoves();
    while (solve(moves));
}