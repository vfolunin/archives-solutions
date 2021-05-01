#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int speciesCount;
    if (!(cin >> speciesCount))
        return 0;

    vector<vector<int>> consumes(speciesCount, vector<int>(speciesCount));
    for (int a = 0; a < speciesCount; a++)
        for (int b = 0; b < speciesCount; b++)
            cin >> consumes[a][b];

    vector<vector<int>> chains;

    for (int a = 0; a < speciesCount; a++)
        for (int b = a + 1; b < speciesCount; b++)
            for (int c = b + 1; c < speciesCount; c++)
                if (consumes[a][b] && consumes[b][c] && consumes[c][a])
                    chains.push_back({ a, b, c });

    for (int a = 0; a < speciesCount; a++)
        for (int b = 0; b < a; b++)
            for (int c = 0; c < b; c++)
                if (consumes[a][b] && consumes[b][c] && consumes[c][a])
                    chains.push_back({ a, b, c });

    sort(chains.begin(), chains.end());

    for (auto &chain : chains) 
        for (int i = 0; i < 3; i++)
            cout << chain[i] + 1 << (i < 2 ? " " : "\n");
    cout << "total:" << chains.size() << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}