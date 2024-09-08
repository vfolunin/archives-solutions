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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, queryCount;
    cin >> vertexCount >> queryCount;

    vector<vector<int>> to(30, vector<int>(vertexCount));
    for (int v = 0; v < vertexCount; v++) {
        cin >> to[0][v];
        to[0][v]--;
    }

    for (int bit = 1; bit < to.size(); bit++)
        for (int v = 0; v < vertexCount; v++)
            to[bit][v] = to[bit - 1][to[bit - 1][v]];

    for (int i = 0; i < queryCount; i++) {
        int v, count;
        cin >> v >> count;
        v--;

        for (int bit = to.size() - 1; bit >= 0; bit--)
            if (count & (1 << bit))
                v = to[bit][v];

        cout << v + 1 << "\n";
    }
}