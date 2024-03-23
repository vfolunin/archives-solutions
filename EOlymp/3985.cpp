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

    vector<int> inDegree(vertexCount), outDegree(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;
            outDegree[a] += hasEdge;
            inDegree[b] += hasEdge;
        }
    }

    for (int v = 0; v < vertexCount; v++)
        cout << inDegree[v] << " " << outDegree[v] << "\n";
}