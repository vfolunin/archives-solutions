#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int moveCount, size;
    cin >> moveCount >> size;

    vector<int> y(moveCount), x(moveCount);
    for (int move = 0; move < moveCount; move++)
        cin >> y[move] >> x[move];

    map<int, map<int, int>> board;
    int win[3] = {};

    for (int move = 0, player = 1; move < moveCount; move++, player = 3 - player) {
        board[y[move]][x[move]] = player;

        static int dy[] = { 1, 0, 1, -1 };
        static int dx[] = { 0, 1, 1, 1 };

        for (int d = 0; d < 4; d++) {
            for (int i = 0; i < size; i++) {
                bool ok = 1;
                for (int j = 0; ok && j < size; j++) {
                    int ty = y[move] + (j - i) * dy[d];
                    int tx = x[move] + (j - i) * dx[d];
                    ok &= board[ty][tx] == player;
                }
                win[player] |= ok;
            }
        }
    }

    cout << "Case " << test << ": ";
    if (!win[1] && !win[2])
        cout << "none\n";
    else if (win[1] && !win[2])
        cout << "crosses\n";
    else if (!win[1] && win[2])
        cout << "noughts\n";
    else
        cout << "error\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}