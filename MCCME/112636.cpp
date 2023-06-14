#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<int> outDegree(vertexCount), inDegree(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;
            if (hasEdge) {
                outDegree[a]++;
                inDegree[b]++;
            }
        }
    }

    bool found = 0;
    for (int v = 0; v < vertexCount; v++) {
        if (!outDegree[v] && !inDegree[v]) {
            cout << v + 1 << " ";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}