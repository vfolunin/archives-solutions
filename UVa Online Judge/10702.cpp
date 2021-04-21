#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount, startVertex, finishCount, moveCount;
    cin >> vertexCount >> startVertex >> finishCount >> moveCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> bonus(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> bonus[a][b];

    vector<vector<int>> maxBonus(moveCount + 1, vector<int>(vertexCount, -1e9));
    maxBonus[0][startVertex - 1] = 0;

    for (int i = 0; i < moveCount; i++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                if (a != b && maxBonus[i][a] != -1e9)
                    maxBonus[i + 1][b] = max(maxBonus[i + 1][b], maxBonus[i][a] + bonus[a][b]);

    int res = 0;
    for (int i = 0; i < finishCount; i++) {
        int finishVertex;
        cin >> finishVertex;
        res = max(res, maxBonus.back()[finishVertex - 1]);
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}