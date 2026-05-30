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

    int minDegree, vertexConnectivity, edgeConnectivity;
    cin >> minDegree >> vertexConnectivity >> edgeConnectivity;

    if (minDegree < edgeConnectivity || edgeConnectivity < vertexConnectivity) {
        cout << "0 0";
        return 0;
    }

    int halfVertexCount = minDegree + 1;
    int halfEdgeCount = halfVertexCount * (halfVertexCount - 1) / 2;

    int vertexCount = 2 * halfVertexCount;
    int edgeCount = 2 * halfEdgeCount + edgeConnectivity;

    cout << vertexCount << " " << edgeCount << "\n";

    for (int a = 0; a < halfVertexCount; a++)
        for (int b = a + 1; b < halfVertexCount; b++)
            cout << a + 1 << " " << b + 1 << "\n";

    for (int i = 0; i < edgeConnectivity; i++)
        cout << i + 1 << " " << halfVertexCount + i % vertexConnectivity + 1 << "\n";

    for (int a = halfVertexCount; a < vertexCount; a++)
        for (int b = a + 1; b < vertexCount; b++)
            cout << a + 1 << " " << b + 1 << "\n";
}