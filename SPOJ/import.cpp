#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int planetCount;
    if (!(cin >> planetCount))
        return 0;

    vector<double> bonus(26);
    vector<vector<int>> dist(27, vector<int>(27, 1e9));
    for (int v = 0; v < 26; v++)
        dist[v][v] = 0;

    for (int i = 0; i < planetCount; i++) {
        char v;
        cin >> v >> bonus[v - 'A'];
        string adjancent;
        cin >> adjancent;
        for (char to : adjancent) {
            if (to == '*')
                dist[v - 'A'][26] = dist[26][v - 'A'] = 1;
            else
                dist[v - 'A'][to - 'A'] = dist[to - 'A'][v - 'A'] = 1;
        }
    }

    for (int v = 0; v < 27; v++)
        for (int a = 0; a < 27; a++)
            for (int b = 0; b < 27; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int best = 0;
    double bestBonus = bonus[0] * pow(0.95, dist[26][0]);
    for (int v = 1; v < 26; v++) {
        double vBonus = bonus[v] * pow(0.95, dist[26][v]);
        if (bestBonus < vBonus) {
            bestBonus = vBonus;
            best = v;
        }
    }

    cout << "Import from " << (char)(best + 'A') << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}