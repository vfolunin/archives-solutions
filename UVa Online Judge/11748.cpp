#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool wins(vector<vector<int>> &rank, int a, int b) {
    int winCount = 0;
    for (vector<int> &r : rank)
        winCount += find(r.begin(), r.end(), a) < find(r.begin(), r.end(), b);
    return winCount * 2 > rank.size();
}

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

bool solve() {
    int candidateCount, voterCount, winner;
    cin >> candidateCount >> voterCount >> winner;

    if (!candidateCount)
        return 0;
    winner--;

    vector<vector<int>> rank(voterCount, vector<int>(candidateCount));
    for (vector<int> &r : rank) {
        for (int &x : r) {
            cin >> x;
            x--;
        }
    }

    vector<vector<int>> graph(candidateCount);
    for (int a = 0; a < candidateCount; a++) {
        for (int b = a + 1; b < candidateCount; b++) {
            if (wins(rank, a, b))
                graph[a].push_back(b);
            else
                graph[b].push_back(a);
        }
    }

    vector<int> visited(candidateCount);
    dfs(graph, winner, visited);

    if (!count(visited.begin(), visited.end(), 0))
        cout << "yes\n";
    else
        cout << "no\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}