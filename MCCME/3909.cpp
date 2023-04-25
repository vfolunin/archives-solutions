#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(vector<vector<int>> &graphA, int vFromA, vector<int> &visited, int i, vector<int> &pairFromA) {
    visited[vFromA] = i;

    for (int vFromB : graphA[vFromA]) {
        int &toFromA = pairFromA[vFromB];

        if (toFromA == -1 || visited[toFromA] != i && dfs(graphA, toFromA, visited, i, pairFromA)) {
            toFromA = vFromA;
            return 1;
        }
    }

    return 0;
}

vector<int> kuhn(vector<vector<int>> &graphA, int vertexCountB) {
    vector<int> visited(graphA.size(), -1);
    vector<int> pairFromA(vertexCountB, -1);

    for (int vFromA = 0; vFromA < graphA.size(); vFromA++)
        dfs(graphA, vFromA, visited, vFromA, pairFromA);

    return pairFromA;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCountA, vertexCountB;
    cin >> vertexCountA >> vertexCountB;

    vector<vector<int>> graphA(vertexCountA);
    for (int a = 0; a < vertexCountA; a++) {
        while (1) {
            int b;
            cin >> b;

            if (!b)
                break;

            graphA[a].push_back(b - 1);
        }
    }

    vector<int> pairFromA = kuhn(graphA, vertexCountB);

    cout << vertexCountB - count(pairFromA.begin(), pairFromA.end(), -1) << "\n";
    for (int b = 0; b < vertexCountB; b++)
        if (pairFromA[b] != -1)
            cout << pairFromA[b] + 1 << " " << b + 1 << "\n";
}