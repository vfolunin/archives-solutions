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

    vector<int> isSource(vertexCount, 1), isSink(vertexCount, 1);

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;

            if (hasEdge) {
                isSink[a] = 0;
                isSource[b] = 0;
            }
        }
    }

    cout << count(isSource.begin(), isSource.end(), 1) << "\n";
    for (int v = 0; v < vertexCount; v++)
        if (isSource[v])
            cout << v + 1 << "\n";

    cout << count(isSink.begin(), isSink.end(), 1) << "\n";
    for (int v = 0; v < vertexCount; v++)
        if (isSink[v])
            cout << v + 1 << "\n";
}