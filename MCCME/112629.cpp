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

    string line;
    getline(cin, line);

    vector<vector<int>> hasEdge(vertexCount, vector<int>(vertexCount));
    for (int v = 0; v < vertexCount; v++) {
        getline(cin, line);
        stringstream ss(line);
        int to;
        while (ss >> to)
            if (to)
                hasEdge[v][to - 1] = 1;
    }

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++)
            cout << hasEdge[a][b] << " ";
        cout << "\n";
    }
}