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

    set<pair<int, int>> edges;
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b)
            swap(a, b);

        edges.insert({ a, b });
    }

    int res = 0;
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b)
            swap(a, b);

        res += !edges.count({ a, b });
    }

    cout << res;
}