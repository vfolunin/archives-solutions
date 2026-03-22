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

    vector<vector<int>> graphR(vertexCount);
    vector<int> outDegree(vertexCount);

    for (int v = 0; v < vertexCount; v++) {
        int inDegree;
        cin >> inDegree;
        for (int i = 0; i < inDegree; i++) {
            int from;
            cin >> from;
            graphR[v].push_back(from - 1);
            outDegree[from - 1]++;
        }
    }

    set<int> q;
    for (int v = 0; v < vertexCount; v++)
        if (!outDegree[v])
            q.insert(v);

    vector<int> order(vertexCount);
    for (int &v : order) {
        v = *prev(q.end());
        q.erase(prev(q.end()));

        for (int from : graphR[v])
            if (!--outDegree[from])
                q.insert(from);
    }
    reverse(order.begin(), order.end());

    for (int v : order)
        cout << v + 1 << " ";
}