#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<vector<int>> &dist, int cycleSize, int sum, vector<int> &cycle, int &minSum, vector<int> &minCycle) {
    if (cycle.size() == cycleSize) {
        if (dist[cycle.back()][cycle.front()]) {
            sum += dist[cycle.back()][cycle.front()];
            if (minSum > sum || minSum == sum && minCycle > cycle) {
                minSum = sum;
                minCycle = cycle;
            }
        }
        return;
    }

    for (int v = 0; v < dist.size(); v++) {
        if ((cycle.empty() || dist[cycle.back()][v]) && !count(cycle.begin(), cycle.end(), v)) {
            int delta = cycle.empty() ? 0 : dist[cycle.back()][v];
            cycle.push_back(v);
            rec(dist, cycleSize, sum + delta, cycle, minSum, minCycle);
            cycle.pop_back();
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> dist[a][b];

    int cycleSize;
    cin >> cycleSize;

    vector<int> cycle, minCycle;
    int minSum = 1e9;
    rec(dist, cycleSize, 0, cycle, minSum, minCycle);

    if (minSum != 1e9) {
        cout << minSum << "\n";
        for (int v : minCycle)
            cout << v + 1 << " ";
        cout << minCycle.front() + 1;
    } else {
        cout << 0;
    }
}