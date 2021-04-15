#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    vector<vector<int>> graph(26);
    vector<bool> isTerm(26);
    for (int i = 0; i < vertexCount; i++) {
        char v, to0, to1, term;
        cin >> v >> to0 >> to1 >> term;

        graph[v - 'A'].push_back(to0 - 'A');
        graph[v - 'A'].push_back(to1 - 'A');
        isTerm[v - 'A'] = term == 'x';
    }

    int moves;
    cin >> moves;

    vector<vector<long long>> ways(26, vector<long long>(moves + 1));
    for (int v = 0; v < vertexCount; v++)
        ways[v][0] = isTerm[v];
    for (int m = 1; m <= moves; m++)
        for (int v = 0; v < vertexCount; v++)
            ways[v][m] = ways[graph[v][0]][m - 1] + ways[graph[v][1]][m - 1];

    cout << ways[0][moves] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}