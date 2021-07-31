#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int size, edgeCount;
    cin >> size >> edgeCount;

    if (!size)
        return 0;

    vector<int> time(edgeCount);
    vector<int> fromMask(edgeCount);
    vector<int> fromVal(edgeCount);
    vector<int> to0(edgeCount);
    vector<int> to1(edgeCount);

    for (int i = 0; i < edgeCount; i++) {
        string from, to;
        cin >> time[i] >> from >> to;
        for (int j = 0; j < size; j++) {
            if (from[j] != '0')
                fromMask[i] |= 1 << j;
            if (from[j] == '+')
                fromVal[i] |= 1 << j;
            if (to[j] == '-')
                to0[i] |= 1 << j;
            if (to[j] == '+')
                to1[i] |= 1 << j;
        }
        to0[i] = ~to0[i];
    }

    vector<int> dist(1 << size, 1e9);
    set<pair<int, int>> q;

    dist[(1 << size) - 1] = 0;
    q.insert({ 0, (1 << size) - 1 });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (int i = 0; i < edgeCount; i++) {
            if ((v & fromMask[i]) == fromVal[i]) {
                int to = v & to0[i] | to1[i];
                if (dist[to] > dist[v] + time[i]) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + time[i];
                    q.insert({ dist[to], to });
                }
            }
        }
    }

    cout << "Product " << test << "\n";
    if (dist[0] == 1e9)
        cout << "Bugs cannot be fixed.\n\n";
    else
        cout << "Fastest sequence takes " << dist[0] << " seconds.\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int test = 1; solve(test); test++);
}