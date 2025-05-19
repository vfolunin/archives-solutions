#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int vertexCount;
    cin >> vertexCount;

    vector<int> inDegree(vertexCount), outDegree(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;

            outDegree[a] += hasEdge;
            inDegree[b] += hasEdge;
        }
    }

    for (int v = 0; v < vertexCount; v++) {
        if (inDegree[v] == vertexCount && outDegree[v] == 1) {
            cout << v + 1 << "\n";
            return;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}