#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount, queryCount;
    if (!(cin >> vertexCount >> queryCount))
        return 0;

    vector<unordered_set<int>> group(vertexCount);
    vector<int> groupOf(vertexCount);
    vector<long long> groupSum(vertexCount);

    for (int v = 0; v < vertexCount; v++) {
        group[v].insert(v);
        groupOf[v] = v;
        groupSum[v] = v + 1;
    }

    auto moveV = [&](int v, int a, int b) {
        group[a].erase(v);
        group[b].insert(v);
        groupOf[v] = b;
        groupSum[a] -= v + 1;
        groupSum[b] += v + 1;
    };

    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            cin >> a >> b;

            a = groupOf[a - 1];
            b = groupOf[b - 1];
            if (a == b)
                continue;

            if (group[a].size() > group[b].size())
                swap(a, b);

            while (!group[a].empty())
                moveV(*group[a].begin(), a, b);
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;

            int v = a - 1;
            a = groupOf[a - 1];
            b = groupOf[b - 1];
            if (a == b)
                continue;

            moveV(v, a, b);
        } else {
            int v;
            cin >> v;

            v--;

            cout << group[groupOf[v]].size() << " " << groupSum[groupOf[v]] << "\n";
        }
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}