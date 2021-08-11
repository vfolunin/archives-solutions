#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount)
        return 0;

    vector<pair<int, int>> edges(edgeCount);
    for (auto &[a, b] : edges) {
        cin >> a >> b;
        if (a < b)
            swap(a, b);
    }

    string res(vertexCount, '0');
    sort(edges.rbegin(), edges.rend());

    for (auto &[a, b] : edges)
        if (res[a] == '0' && res[b] == '0')
            res[b] = '1';
    
    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}