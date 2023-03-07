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

    vector<vector<int>> adjacent(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> adjacent[a][b];

    int directedEdgeCount = 0, undirectedEdgeCount = 0;
    for (int a = 0; a < vertexCount; a++) {
        for (int b = a + 1; b < vertexCount; b++) {
            if (adjacent[a][b] == adjacent[b][a]) {
                undirectedEdgeCount += adjacent[a][b] != 0;
            } else {
                directedEdgeCount += adjacent[a][b] != 0;
                directedEdgeCount += adjacent[b][a] != 0;
            }
        }
    }

    cout << directedEdgeCount << " " << undirectedEdgeCount;
}