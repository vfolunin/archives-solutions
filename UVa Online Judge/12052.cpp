#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string name;
    cin >> name;
    cout << name << "\n";

    if (name == "TheEnd")
        return 0;

    int vertexCount, coloredVertexCount, edgeCount;
    cin >> vertexCount >> coloredVertexCount >> edgeCount;

    vector<string> edges(edgeCount);
    for (string &edge : edges)
        cin >> edge;

    string mask = string(vertexCount - coloredVertexCount, '0') + string(coloredVertexCount, '1');
    int res = 0;
    do {
        vector<int> neighbors(vertexCount);
        for (string &edge : edges) {
            if (mask[edge[0] - 'A'] == '0' && mask[edge[1] - 'A'] == '1')
                neighbors[edge[0] - 'A']++;
            if (mask[edge[1] - 'A'] == '0' && mask[edge[0] - 'A'] == '1')
                neighbors[edge[1] - 'A']++;
        }
        res += *max_element(neighbors.begin(), neighbors.end()) <= 1;
    } while (next_permutation(mask.begin(), mask.end()));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}