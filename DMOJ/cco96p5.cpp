#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

string bfs(vector<string> &graph, char start, char finish) {
    vector<int> dist(26, 1e9);
    string from(26, ' ');
    queue<char> q;

    dist[start - 'A'] = 0;
    q.push(start);

    while (!q.empty()) {
        char v = q.front();
        q.pop();

        for (char to : graph[v - 'A']) {
            if (dist[to - 'A'] > dist[v - 'A'] + 1) {
                dist[to - 'A'] = dist[v - 'A'] + 1;
                from[to - 'A'] = v;
                q.push(to);
            }
        }
    }

    string path;
    for (char c = finish; c != ' '; c = from[c - 'A'])
        path.push_back(c);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int edgeCount, queryCount;
    cin >> edgeCount >> queryCount;

    vector<string> graph(26);
    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        cin >> a >> b;

        graph[a[0] - 'A'].push_back(b[0]);
        graph[b[0] - 'A'].push_back(a[0]);
    }

    for (int i = 0; i < queryCount; i++) {
        string a, b;
        cin >> a >> b;

        cout << bfs(graph, a[0], b[0]) << "\n";
    }
}