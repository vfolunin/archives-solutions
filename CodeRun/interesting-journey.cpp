#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<int> &x, vector<int> &y, int limit, int start, int finish) {
    vector<int> dist(x.size(), 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push({ start });

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == finish)
            return dist[v];

        for (int to = 0; to < x.size(); to++) {
            if ((long long)abs(x[v] - x[to]) + abs(y[v] - y[to]) <= limit && dist[to] > dist[v] + 1) {
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

    int pointCount;
    cin >> pointCount;

    vector<int> x(pointCount), y(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i];

    int limit, start, finish;
    cin >> limit >> start >> finish;

    cout << bfs(x, y, limit, start - 1, finish - 1);
}