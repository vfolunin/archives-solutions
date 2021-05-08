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

    vector<vector<double>> dist(vertexCount, vector<double>(vertexCount, 1e9));
    vector<vector<double>> next(vertexCount, vector<double>(vertexCount, -1));

    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int i = 0; i < vertexCount; i++) {
        int v, to;
        char c;
        cin >> v >> c;
        v--;

        while (cin.peek() != '\n') {
            cin >> to;
            to--;
            if (cin.peek() != '\n')
                cin >> c;
            dist[v][to] = 1;
            next[v][to] = to;
        }
    }

    for (int v = 0; v < vertexCount; v++) {
        for (int a = 0; a < vertexCount; a++) {
            for (int b = 0; b < vertexCount; b++) {
                if (dist[a][b] > dist[a][v] + dist[v][b] || 
                    dist[a][b] == dist[a][v] + dist[v][b] && next[a][b] > (a != v ? next[a][v] : next[v][b])) {
                    dist[a][b] = dist[a][v] + dist[v][b];
                    next[a][b] = (a != v ? next[a][v] : next[v][b]);
                }
            }
        }
    }

    int queryCount;
    cin >> queryCount;

    cout << "-----\n";
    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if (dist[a][b] == 1e9) {
            cout << "connection impossible\n";
        } else {
            for (; a != -1; a = next[a][b])
                cout << a + 1 << (a != b ? " " : "\n");
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}