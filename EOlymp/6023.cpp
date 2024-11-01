#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, start, finish, up, down;
    cin >> vertexCount >> start >> finish >> up >> down;

    vector<int> dist(vertexCount, 1e9);
    queue<int> q;

    dist[start - 1] = 0;
    q.push(start - 1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v + up < vertexCount && dist[v + up] == 1e9) {
            dist[v + up] = dist[v] + 1;
            q.push(v + up);
        }
        if (v - down >= 0 && dist[v - down] == 1e9) {
            dist[v - down] = dist[v] + 1;
            q.push(v - down);
        }
    }

    if (dist[finish - 1] == 1e9)
        cout << "use the stairs\n";
    else
        cout << dist[finish - 1] << "\n";
}