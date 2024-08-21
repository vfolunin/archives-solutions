#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(int start, int finish, const vector<int> &ds) {
    vector<int> dist(1.1e6, 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == finish)
            return dist[v];

        for (int d : ds) {
            int to = v + d;
            if (0 < to && to < dist.size() && dist[to] > dist[v] + 1) {
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

    int start, finish, d1, d2;
    cin >> start >> finish >> d1 >> d2;

    cout << bfs(start, finish, { d1, -d2 });
}