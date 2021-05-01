#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int playerCount;
    if (!(cin >> playerCount))
        return 0;

    vector<vector<int>> res(playerCount, vector<int>(playerCount));
    for (int a = 0; a < playerCount; a++)
        for (int b = 0; b < playerCount; b++)
            cin >> res[a][b];

    vector<vector<int>> draws;

    for (int a = 0; a < playerCount; a++) {
        for (int b = a + 1; b < playerCount; b++) {
            for (int c = b + 1; c < playerCount; c++) {
                if (!res[a][b] && !res[b][a] && !res[b][c] && !res[c][b] && !res[a][c] && !res[c][a])
                    draws.push_back({ a, b, c });
                if (res[a][b] && res[b][c] && res[c][a])
                    draws.push_back({ a, b, c });
            }
        }
    }

    for (int a = 0; a < playerCount; a++)
        for (int b = 0; b < a; b++)
            for (int c = 0; c < b; c++)
                if (res[a][b] && res[b][c] && res[c][a])
                    draws.push_back({ a, b, c });

    sort(draws.begin(), draws.end());

    cout << draws.size() << '\n';
    for (auto &draw : draws) 
        for (int i = 0; i < 3; i++)
            cout << draw[i] + 1 << (i < 2 ? ' ' : '\n');
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}