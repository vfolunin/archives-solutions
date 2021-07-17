#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int start, vector<int> &length) {
    vector<pair<int, int>> stack = { { start, -1 } };

    while (!stack.empty()) {
        auto [v, p] = stack.back();
        stack.pop_back();

        if (v == start && p != -1)
            return length[p];

        length[v] = (p != -1 ? length[p] + 1 : 1);
        for (int to : graph[v])
            if (to != p)
                stack.push_back({ to, v });
    }

    return 0;
}

bool solve(int test) {
    int h, w;
    cin >> w >> h;

    if (!h && !w)
        return 0;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    vector<vector<int>> graph((h + 1) * (w + w + 1));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int north = y * (w + w + 1) + x;
            int south = (y + 1) * (w + w + 1) + x;
            int west = y * (w + w + 1) + w + x;
            int east = y * (w + w + 1) + w + x + 1;

            if (a[y][x] == '/') {
                graph[north].push_back(west);
                graph[west].push_back(north);
                graph[south].push_back(east);
                graph[east].push_back(south);
            } else {
                graph[north].push_back(east);
                graph[east].push_back(north);
                graph[south].push_back(west);
                graph[west].push_back(south);
            }
        }
    }

    vector<int> length(graph.size());
    int cycleCount = 0, maxCycleLength = 0;

    for (int v = 0; v < graph.size(); v++) {
        if (length[v])
            continue;
        if (int cycleLength = dfs(graph, v, length); cycleLength) {
            cycleCount++;
            maxCycleLength = max(maxCycleLength, cycleLength);
        }
    }

    cout << "Maze #" << test << ":\n";
    if (cycleCount)
        cout << cycleCount << " Cycles; the longest has length " << maxCycleLength << ".\n\n";
    else
        cout << "There are no cycles.\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}