#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(int start, int finish) {
    vector<int> dist(1001, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : { v + 3, v * 4 }) {
            if (to < dist.size() && dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist[finish];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int start, finish;
    cin >> start >> finish;

    cout << bfs(start, finish);
}