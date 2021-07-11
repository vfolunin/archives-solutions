#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int vertexCount;
    cin >> vertexCount;

    vector<string> vertexName(vertexCount);
    map<string, int> vertexId;
    for (int i = 0; i < vertexCount; i++) {
        cin >> vertexName[i];
        vertexId[vertexName[i]] = i;
    }

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    vector<vector<int>> next(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            cin >> dist[a][b];
            if (dist[a][b] == -1)
                dist[a][b] = 1e9;
            next[a][b] = b;
        }
    }

    for (int v = 0; v < vertexCount; v++) {
        for (int a = 0; a < vertexCount; a++) {
            for (int b = 0; b < vertexCount; b++) {
                if (dist[a][b] > dist[a][v] + dist[v][b]) {
                    dist[a][b] = dist[a][v] + dist[v][b];
                    next[a][b] = v != a ? next[a][v] : next[v][b];
                }
            }
        }
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string name, aName, bName;
        cin >> name >> aName >> bName;

        int a = vertexId[aName], b = vertexId[bName];
        if (dist[a][b] == 1e9) {
            cout << "Sorry Mr " << name << " you can not go from " << aName << " to " << bName << "\n";
        } else {
            cout << "Mr " << name << " to go from " << aName << " to " << bName;
            cout << ", you will receive " << dist[a][b] << " euros\n";
            cout << "Path:" << aName << " ";
            for (int v = next[a][b]; v != b; v = next[v][b])
                cout << vertexName[v] << " ";
            cout << bName << "\n";
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}