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
    
    vector<int> path;
    while (1) {
        path.push_back(start);
        
        if (graph[start].empty())
            break;

        start = *graph[start].begin();
    }
    reverse(path.begin(), path.end());

    cout << 0;
    for (int v : path)
        cout << "#" << v;
}