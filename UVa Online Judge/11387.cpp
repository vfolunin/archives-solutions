#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    if (vertexCount < 4 || vertexCount % 2) {
        cout << "Impossible\n";
        return 1;
    }

    vector<int> p;
    for (int v = 0; v < vertexCount; v++)
        for (int i = 0; i < 3; i++)
            p.push_back(v);

    minstd_rand gen;
    bool ok;
    do {
        shuffle(p.begin(), p.end(), gen);
        set<pair<int, int>> edges;
        ok = 1;
        for (int i = 0; ok && i < p.size(); i += 2) {
            ok &= p[i] != p[i + 1];
            ok &= !edges.count({ p[i], p[i + 1] });
            ok &= !edges.count({ p[i + 1], p[i] });
            edges.insert({ p[i], p[i + 1] });
            edges.insert({ p[i + 1], p[i] });
        }
    } while (!ok);

    cout << p.size() / 2 << "\n";
    for (int i = 0; i < p.size(); i += 2)
        cout << p[i] + 1 << " " << p[i + 1] + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}