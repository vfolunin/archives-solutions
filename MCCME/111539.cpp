#include <iostream>
#include <sstream>
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

    string line;
    getline(cin, line);

    for (int v = 0; v < vertexCount; v++) {
        getline(cin, line);
        stringstream ss(line);

        int to;
        while (ss >> to)
            graph[to - 1].push_back(v);
    }

    cout << vertexCount << "\n";
    for (int v = 0; v < vertexCount; v++) {
        for (int to : graph[v])
            cout << to + 1 << " ";
        cout << "\n";
    }
}