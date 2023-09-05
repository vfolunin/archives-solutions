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

    vector<vector<int>> graph(vertexCount, vector<int>(vertexCount));
    bool isDirected = 0;

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            cin >> graph[a][b];

            if (a == b && graph[a][b]) {
                cout << "NO";
                return 0;
            }

            isDirected |= a > b && graph[a][b] != graph[b][a];
        }
    }

    cout << (isDirected ? "YES" : "NO");
}