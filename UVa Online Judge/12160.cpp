#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int start, finish, deltaCount;
    cin >> start >> finish >> deltaCount;

    if (!start && !finish && !deltaCount)
        return 0;

    vector<int> delta(deltaCount);
    for (int &d : delta)
        cin >> d;

    vector<int> dist(10000, 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int d : delta) {
            if (dist[(v + d) % 10000] == 1e9) {
                dist[(v + d) % 10000] = dist[v] + 1;
                q.push((v + d) % 10000);
            }
        }
    }

    cout << "Case " << test << ": ";
    if (dist[finish] == 1e9)
        cout << "Permanently Locked\n";
    else
        cout << dist[finish] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}