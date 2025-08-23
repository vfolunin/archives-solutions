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

    vector<int> inDegree(vertexCount), outDegree(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        outDegree[a - 1]++;
        inDegree[b - 1]++;
    }

    int start = -1, finish = -1;
    for (int v = 0; v < vertexCount; v++) {
        if (inDegree[v] == outDegree[v]) {
            continue;
        } else if (inDegree[v] + 1 == outDegree[v]) {
            if (start == -1) {
                start = v;
            } else {
                cout << "no";
                return 0;
            }
        } else if (inDegree[v] == outDegree[v] + 1) {
            if (finish == -1) {
                finish = v;
            } else {
                cout << "no";
                return 0;
            }
        } else {
            cout << "no";
            return 0;
        }
    }

    if (start == -1 && finish == -1)
        cout << "anywhere";
    else if (start != -1 && finish != -1)
        cout << start + 1 << " " << finish + 1;
    else
        cout << "no";
}