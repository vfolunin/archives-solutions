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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<map<int, int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, color;
        cin >> a >> b >> color;
        a--;
        b--;

        graph[a][color] = b;
        graph[b][color] = a;
    }

    int opCount;
    cin >> opCount;

    int v = 0;
    for (int i = 0; i < opCount; i++) {
        int color;
        cin >> color;

        if (graph[v].count(color)) {
            v = graph[v][color];
        } else {
            cout << "INCORRECT";
            return 0;
        }
    }

    cout << v + 1;
}