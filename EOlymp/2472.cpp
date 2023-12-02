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

    int vertexCount, opCount;
    cin >> vertexCount >> opCount;

    vector<vector<int>> graph(vertexCount);

    for (int i = 0; i < opCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            graph[a].push_back(b);
            graph[b].push_back(a);
        } else {
            int v;
            cin >> v;
            v--;

            for (int to : graph[v])
                cout << to + 1 << " ";
            cout << "\n";
        }
    }
}