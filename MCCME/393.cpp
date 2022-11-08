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

    vector<pair<int, int>> edges;

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;
            if (hasEdge && a < b)
                edges.push_back({ a, b });
        }
    }

    vector<int> color(vertexCount);
    for (int &c : color)
        cin >> c;

    int res = 0;
    for (auto &[a, b] : edges)
        res += color[a] != color[b];
    cout << res;
}