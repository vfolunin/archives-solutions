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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<int> inDegree(vertexCount), outDegree(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        outDegree[a - 1]++;
        inDegree[b - 1]++;
    }

    for (int v = 0; v < vertexCount; v++)
        cout << inDegree[v] << "\n" << outDegree[v] << "\n";
}