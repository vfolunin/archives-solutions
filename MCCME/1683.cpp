#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(vector<vector<int>> &graphA, int vFromA, vector<int> &visited, vector<int> &pairFromA) {
    visited[vFromA] = 1;

    for (int vFromB : graphA[vFromA]) {
        int &toFromA = pairFromA[vFromB];

        if (toFromA == -1 || !visited[toFromA] && dfs(graphA, toFromA, visited, pairFromA)) {
            toFromA = vFromA;
            return 1;
        }
    }

    return 0;
}

vector<int> kuhn(vector<vector<int>> &graphA, int vertexCountB) {
    vector<int> pairFromA(vertexCountB, -1);

    for (int vFromA = 0; vFromA < graphA.size(); vFromA++) {
        vector<int> visited(graphA.size());
        dfs(graphA, vFromA, visited, pairFromA);
    }

    return pairFromA;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCountA, vertexCountB;
    cin >> vertexCountA >> vertexCountB;

    vector<vector<int>> graphA(vertexCountA);

    for (int vFromA = 0; vFromA < vertexCountA; vFromA++) {
        for (int vFromB = 0; vFromB < vertexCountA; vFromB++) {
            int x;
            cin >> x;

            if (x)
                graphA[vFromA].push_back(vFromB);
        }
    }

    vector<int> pairFromA = kuhn(graphA, vertexCountB);

    cout << vertexCountB - count(pairFromA.begin(), pairFromA.end(), -1);
}