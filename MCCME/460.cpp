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
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> graph[a][b];

    for (int a = 0; a < vertexCount; a++) {
        if (graph[a][a]) {
            cout << "NO";
            return 0;
        }
    }

    for (int a = 0; a < vertexCount; a++) {
        for (int b = a + 1; b < vertexCount; b++) {
            if (graph[a][b] != graph[b][a]) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
}