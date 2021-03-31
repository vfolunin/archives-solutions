#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<int> y(2 * size), x(2 * size);
    for (int i = 0; i < 2 * size; i++) {
        char c;
        cin >> y[i] >> x[i] >> c;
        y[i]--;
        x[i]--;
    }

    vector<vector<string>> board(4, vector<string>(size, string(size, '0')));
    set<vector<string>> boards;

    for (int i = 0; i < 2 * size; i++) {
        for (int j = 0; j < 4; j++) {
            board[j][y[i]][x[i]] ^= 1;
            int ny = x[i];
            int nx = size - 1 - y[i];
            y[i] = ny;
            x[i] = nx;
        }

        for (int j = 0; j < 4; j++) {
            if (boards.count(board[j])) {
                cout << "Player " << 2 - i % 2 << " wins on move " << i + 1 << "\n";
                return 1;
            }
        }

        for (int j = 0; j < 4; j++)
            boards.insert(board[j]);
    }

    cout << "Draw\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}