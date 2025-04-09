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

    vector<vector<int>> hasEdge(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> hasEdge[a][b];

    int degreeSum = 0;
    vector<int> degree(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        int undirectedEdgeCount = 0, directedEdgeCount = 0;
        for (int b = 0; b < vertexCount; b++) {
            if (hasEdge[a][b] && hasEdge[b][a])
                undirectedEdgeCount++;
            else if (hasEdge[a][b] || hasEdge[b][a])
                directedEdgeCount++;
        }

        if (undirectedEdgeCount + directedEdgeCount > 1) {
            degree[a] += undirectedEdgeCount * 2 + directedEdgeCount;
            degreeSum += degree[a];
        }
    }

    cout << degreeSum << "\n";
    for (int degree : degree)
        cout << degree << " ";
}