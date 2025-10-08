#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<unordered_set<int>> followers(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        followers[b - 1].insert(a - 1);
    }

    int res, resCapacity = -1;
    for (int v = 0; v < vertexCount; v++) {
        int capacity = 0;
        for (int to : followers[v])
            capacity += !followers[to].count(v);

        if (resCapacity < capacity) {
            res = v;
            resCapacity = capacity;
        }
    }

    cout << res + 1 << " " << resCapacity;
}