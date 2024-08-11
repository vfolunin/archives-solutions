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

    vector<int> parent(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        cin >> parent[v];

        if (parent[v])
            parent[v]--;
        else
            parent[v] = v;
    }

    for (int v = 0; v < vertexCount; v++) {
        int root = v;
        while (parent[root] != root)
            root = parent[root];

        int currentV = v;
        while (parent[currentV] != root) {
            int nextV = parent[currentV];
            parent[currentV] = root;
            currentV = nextV;
        }

        cout << (root == v ? 0 : root + 1) << "\n";
    }
}