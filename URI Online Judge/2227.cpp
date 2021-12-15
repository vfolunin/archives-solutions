#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    vector<int> degree(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        degree[a - 1]++;
        degree[b - 1]++;
    }

    int maxDegree = *max_element(degree.begin(), degree.end());

    cout << "Teste " << test << "\n";
    for (int v = 0; v < vertexCount; v++)
        if (degree[v] == maxDegree)
            cout << v + 1 << " ";
    cout << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}