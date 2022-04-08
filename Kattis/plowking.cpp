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

    long long vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    long long aVertexCount = 1;
    while (1) {
        long long maxAEdgeCount = aVertexCount * (aVertexCount - 1) / 2;
        long long bEdgeCount = vertexCount - aVertexCount;
        if (maxAEdgeCount + bEdgeCount >= edgeCount)
            break;
        aVertexCount++;
    }

    long long mstWeight = 0;
    for (long long v = 1, minEdge = 1; v < aVertexCount; v++, minEdge += v - 1)
        mstWeight += minEdge;
    for (long long v = 0; v < vertexCount - aVertexCount; v++)
        mstWeight += edgeCount - v;

    cout << mstWeight;
}