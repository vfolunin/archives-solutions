#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<unordered_set<int>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == finish)
            return dist[v];

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<unordered_set<int>> graph = {
        {}, {6}, {6}, {4, 5, 6, 15}, {3, 5, 6},
        {3, 4, 6}, {1, 2, 3, 4, 5, 7}, {6, 8}, {7, 9}, {8, 10, 12},
        {9, 11}, {10, 12}, {9, 11, 13}, {12, 14, 15}, {13},
        {3, 13}, {17, 18}, {16, 18}, {16, 17}
    };
    graph.resize(50);

    for (char op; cin >> op; ) {
        if (op == 'i') {
            int a, b;
            cin >> a >> b;

            graph[a].insert(b);
            graph[b].insert(a);
        } else if (op == 'd') {
            int a, b;
            cin >> a >> b;

            graph[a].erase(b);
            graph[b].erase(a);
        } else if (op == 'n') {
            int v;
            cin >> v;

            cout << graph[v].size() << "\n";
        } else if (op == 'f') {
            int v;
            cin >> v;

            unordered_set<int> friendsOfFriends;
            for (int to : graph[v])
                friendsOfFriends.insert(graph[to].begin(), graph[to].end());
            friendsOfFriends.erase(v);
            for (int to : graph[v])
                friendsOfFriends.erase(to);

            cout << friendsOfFriends.size() << "\n";
        } else if (op == 's') {
            int a, b;
            cin >> a >> b;

            int dist = bfs(graph, a, b);

            if (dist != -1)
                cout << dist << "\n";
            else
                cout << "Not connected\n";
        } else {
            break;
        }
    }
}