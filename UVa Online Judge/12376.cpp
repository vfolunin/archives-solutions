#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<int> bonus(vertexCount);
    for (int &b : bonus)
        cin >> b;

    vector<int> to(vertexCount, -1);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        if (to[a] == -1 || bonus[b] > bonus[to[a]])
            to[a] = b;
    }

    int v = 0, totalBonus = 0;
    while (1) {
        totalBonus += bonus[v];
        if (to[v] == -1)
            break;
        v = to[v];
    }

    cout << "Case " << test << ": " << totalBonus << " " << v << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}