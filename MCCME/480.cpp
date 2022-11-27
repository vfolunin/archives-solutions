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

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            for (int c = 0; c < vertexCount; c++) {
                if (a != b && b != c && a != c && hasEdge[a][b] && hasEdge[b][c] && !hasEdge[a][c]) {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }

    cout << "YES";
}