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

    vector<int> inDegree(vertexCount);

    for (int v = 0; v < vertexCount; v++) {
        int adjCount;
        cin >> adjCount;

        for (int i = 0; i < adjCount; i++) {
            int to;
            cin >> to;
            inDegree[to - 1]++;
        }
    }

    cout << count(inDegree.begin(), inDegree.end(), 0);
}