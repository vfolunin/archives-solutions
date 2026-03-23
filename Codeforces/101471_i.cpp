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

    int edgeCount, queryCount;
    cin >> edgeCount >> queryCount;

    vector<vector<int>> reachable(26, vector<int>(26));
    for (int v = 0; v < 26; v++)
        reachable[v][v] = 1;

    for (int i = 0; i < edgeCount; i++) {
        char a, b;
        cin >> a >> b;
        reachable[a - 'a'][b - 'a'] = 1;
    }

    for (int v = 0; v < 26; v++)
        for (int a = 0; a < 26; a++)
            for (int b = 0; b < 26; b++)
                reachable[a][b] |= reachable[a][v] && reachable[v][b];

    for (int i = 0; i < queryCount; i++) {
        string wordA, wordB;
        cin >> wordA >> wordB;

        bool ok = wordA.size() == wordB.size();
        for (int j = 0; ok && j < wordA.size(); j++)
            ok &= reachable[wordA[j] - 'a'][wordB[j] - 'a'];

        cout << (ok ? "yes\n" : "no\n");
    }
}