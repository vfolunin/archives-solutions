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

    if (edgeCount != vertexCount * (vertexCount - 1) / 2) {
        cout << "NO";
        return 0;
    }

    set<pair<int, int>> seen;
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b)
            swap(a, b);

        if (a == b || seen.count({ a, b })) {
            cout << "NO";
            return 0;
        }
        seen.insert({ a, b });
    }

    cout << "YES";
}