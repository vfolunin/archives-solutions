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

    vector<int> degree(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        degree[a]++;
        degree[b]++;
    }

    int threshold;
    cin >> threshold;

    cout << count_if(degree.begin(), degree.end(), [&](int value) {
        return value >= threshold;
    }) << "\n";

    for (int v = 0; v < degree.size(); v++)
        if (degree[v] >= threshold)
            cout << v + 1 << " ";
}