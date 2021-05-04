#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int vertexCount, dayCount;
    if (!(cin >> vertexCount >> dayCount) || !vertexCount)
        return 0;

    vector<vector<vector<int>>> schedule(vertexCount, vector<vector<int>>(vertexCount));
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            if (a == b)
                continue;

            int scheduleSize;
            cin >> scheduleSize;
            schedule[a][b].resize(scheduleSize);

            for (int &s : schedule[a][b])
                cin >> s;
        }
    }

    vector<vector<int>> cost(dayCount + 1, vector<int>(vertexCount, 1e9));
    cost[0][0] = 0;

    for (int day = 0; day < dayCount; day++) {
        for (int v = 0; v < vertexCount; v++) {
            if (cost[day][v] == 1e9)
                continue;

            for (int to = 0; to < vertexCount; to++) {
                if (v == to || !schedule[v][to][day % schedule[v][to].size()])
                    continue;

                cost[day + 1][to] = min(cost[day + 1][to], cost[day][v] + schedule[v][to][day % schedule[v][to].size()]);
            }
        }
    }

    cout << "Scenario #" << test << "\n";
    if (cost[dayCount][vertexCount - 1] != 1e9)
        cout << "The best flight costs " << cost[dayCount][vertexCount - 1] << ".\n\n";
    else
        cout << "No flight possible.\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}