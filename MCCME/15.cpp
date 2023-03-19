#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> getLcp(vector<string> &name) {
    int vertexCount = name.size();
    vector<pair<string, int>> sortedNames;
    for (int v = 0; v < vertexCount; v++)
        sortedNames.push_back({ name[v], v });
    sort(sortedNames.begin(), sortedNames.end());

    vector<int> lcps(vertexCount);
    for (int i = 0; i + 1 < vertexCount; i++) {
        string &a = sortedNames[i].first;
        string &b = sortedNames[i + 1].first;
        int &p = lcps[i];
        while (p < a.size() && p < b.size() && a[p] == b[p])
            p++;
    }

    vector<vector<int>> lcp(vertexCount, vector<int>(vertexCount));
    for (int i = 0; i < vertexCount; i++) {
        int ai = sortedNames[i].second;
        lcp[ai][ai] = sortedNames[i].first.size();
        for (int j = i + 1; j < vertexCount; j++) {
            int pi = sortedNames[j - 1].second;
            int bi = sortedNames[j].second;
            lcp[ai][bi] = lcp[bi][ai] = min(lcp[ai][pi], lcps[j - 1]);
        }
    }
    return lcp;
}

vector<string> dijkstra(vector<string> &names, vector<vector<int>> &weight, vector<vector<int>> &type, int start, int finish) {
    int vertexCount = names.size();
    vector<int> visited(vertexCount);
    vector<int> dist(vertexCount, 1e9);
    dist[start] = 0;
    vector<int> from(vertexCount, -1);

    for (int i = 0; i < vertexCount; i++) {
        int v = -1;
        for (int j = 0; j < vertexCount; j++)
            if (!visited[j] && (v == -1 || dist[v] > dist[j]))
                v = j;

        visited[v] = 1;

        for (int to = 0; to < vertexCount; to++) {
            if (dist[to] > dist[v] + weight[v][to]) {
                dist[to] = dist[v] + weight[v][to];
                from[to] = v;
            }
        }
    }

    vector<string> path;
    for (int v = finish; v != start; v = from[v]) {
        if (type[from[v]][v] == 0) {
            for (int i = 0; i < weight[from[v]][v]; i++)
                path.push_back("down");
        } else if (type[from[v]][v] == 1) {
            for (int i = 0; i < weight[from[v]][v]; i++)
                path.push_back("up");
        } else {
            for (int i = weight[from[v]][v] - 2; i >= 0; i--)
                path.push_back(string(1, names[v][i]));
            path.push_back("Alt");
        }
    };
    return { path.rbegin(), path.rend() };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount;
    cin >> vertexCount;

    vector<string> names(vertexCount);
    for (string &name : names)
        cin >> name;

    vector<vector<int>> weight(vertexCount, vector<int>(vertexCount));
    vector<vector<int>> type(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            if (a == b)
                continue;

            weight[a][b] = (a < b ? b - a : vertexCount - a + b);
            type[a][b] = 0;

            int candidateWeight = (a < b ? vertexCount - b + a : a - b);
            if (weight[a][b] > candidateWeight) {
                weight[a][b] = candidateWeight;
                type[a][b] = 1;
            }
        }
    }

    vector<vector<int>> lcp = getLcp(names);
    for (int b = 0; b < vertexCount; b++) {
        int candidateWeight = 0;

        for (int shift = 1; shift < vertexCount; shift++) {
            int a = (b - shift + vertexCount) % vertexCount;

            candidateWeight = max(candidateWeight, 1 + lcp[a][b] + 1);
            if (candidateWeight > names[b].size() + 1)
                continue;

            if (weight[a][b] > candidateWeight) {
                weight[a][b] = candidateWeight;
                type[a][b] = 2;
            }
        }
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0, start = 0, finish; i < queryCount; i++, start = finish) {
        cin >> finish;
        finish--;

        vector<string> path = dijkstra(names, weight, type, start, finish);

        cout << path.size() << "\n";
        for (string &s : path)
            cout << s << "\n";
    }
}