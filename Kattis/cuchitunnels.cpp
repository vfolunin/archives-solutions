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

    vector<int> degree(vertexCount);
    for (int &d : degree)
        cin >> d;

    int childCount = 0;
    for (int v = vertexCount - 1; v > 0; v--) {
        if (childCount < degree[v] - 1) {
            cout << "NO";
            return 0;
        }
        childCount = max(0, childCount - (degree[v] - 1)) + 1;
    }

    cout << (childCount == degree[0] ? "YES" : "NO");
}