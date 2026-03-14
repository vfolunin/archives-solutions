#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(int floorCount, int start, int finish, int up, int down) {
    vector<int> dist(floorCount, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : { v + up, v - down }) {
            if (0 <= to && to < floorCount && dist[to] == -1) {
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

    int floorCount, start, finish, up, down;
    cin >> floorCount >> start >> finish >> up >> down;

    int res = bfs(floorCount, start - 1, finish - 1, up, down);

    if (res != -1)
        cout << res;
    else
        cout << "use the stairs";
}