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

    vector<int> from(vertexCount);
    for (int v = 1; v < vertexCount; v++) {
        cin >> from[v];
        from[v]--;
    }

    vector<int> path = { vertexCount - 1 };
    while (path.back())
        path.push_back(from[path.back()]);

    reverse(path.begin(), path.end());

    for (int v : path)
        cout << v + 1 << " ";
}