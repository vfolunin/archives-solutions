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

    vector<vector<int>> graph(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;

            if (hasEdge)
                graph[a].push_back(b);
        }
    }

    int res = 0;
    for (int a = 0; a < vertexCount; a++)
        for (int b : graph[a])
            if (a < b)
                for (int c : graph[b])
                    res += b < c && binary_search(graph[c].begin(), graph[c].end(), a);

    cout << res;
}