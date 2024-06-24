#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
    }

    cout << vertexCount - 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
        solve();
}