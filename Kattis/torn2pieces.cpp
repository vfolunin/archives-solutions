#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> bfs(map<string, set<string>> &graph, string &start, string &finish) {
    map<string, string> prev;
    queue<string> q;

    prev[start];
    q.push(start);

    while (!q.empty()) {
        string v = q.front();
        q.pop();

        for (const string &to : graph[v]) {
            if (!prev.count(to)) {
                prev[to] = v;
                q.push(to);
            }
        }
    }

    if (!prev.count(finish))
        return {};

    vector<string> path;
    for (string v = finish; !v.empty(); v = prev[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pieceCount;
    cin >> pieceCount;

    map<string, set<string>> graph;

    for (int i = 0; i < pieceCount; i++) {
        string a;
        cin >> a;

        string b;
        do {
            cin >> b;
            graph[a].insert(b);
            graph[b].insert(a);
        } while (cin.peek() == ' ');
    }

    string start, finish;
    cin >> start >> finish;

    vector<string> path = bfs(graph, start, finish);
    if (path.empty()) {
        cout << "no route found";
    } else {
        for (string &v : path)
            cout << v << " ";
    }
}