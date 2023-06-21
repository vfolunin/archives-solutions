#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < vertexCount; i++) {
        int v, from;
        cin >> v >> from;
        if (from)
            graph[v].insert(from);
    }

    int start;
    cin >> start;
    
    while (!graph[start].empty())
        start = *graph[start].begin();

    cout << start;
}