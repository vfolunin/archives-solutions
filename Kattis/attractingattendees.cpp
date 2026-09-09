#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int aSize, bSize, aThreshold;
    cin >> aSize >> bSize >> aThreshold;

    vector<unordered_set<int>> aEdges(aSize), bEdges(bSize);
    for (int b = 0; b < bSize; b++) {
        int edgeCount;
        cin >> edgeCount;

        for (int i = 0; i < edgeCount; i++) {
            int a;
            cin >> a;
            a--;

            aEdges[a].insert(b);
            bEdges[b].insert(a);
        }
    }

    vector<int> bThreshold(bSize);
    for (int b = 0; b < bSize; b++)
        bThreshold[b] = bEdges[b].size();

    set<pair<int, int>> aOrder;
    for (int a = 0; a < aSize; a++)
        aOrder.insert({ aEdges[a].size(), a });

    set<pair<int, int>> bOrder;
    for (int b = 0; b < bSize; b++)
        bOrder.insert({ bEdges[b].size() * 2 - bThreshold[b], b });

    while (1) {
        bool changed = 0;

        while (!aOrder.empty() && aOrder.begin()->first < aThreshold) {
            int a = aOrder.begin()->second;
            aOrder.erase(aOrder.begin());

            for (int b : aEdges[a]) {
                bOrder.erase({ bEdges[b].size() * 2 - bThreshold[b], b});
                bEdges[b].erase(a);
                bOrder.insert({ bEdges[b].size() * 2 - bThreshold[b], b });
            }

            changed = 1;
        }

        while (!bOrder.empty() && bOrder.begin()->first < 0) {
            int b = bOrder.begin()->second;
            bOrder.erase(bOrder.begin());

            for (int a : bEdges[b]) {
                aOrder.erase({ aEdges[a].size(), a });
                aEdges[a].erase(b);
                aOrder.insert({ aEdges[a].size(), a });
            }

            changed = 1;
        }

        if (!changed)
            break;
    }

    if (aOrder.empty()) {
        cout << "impossible";
        return 0;
    }

    cout << "possible\n" << aOrder.size() << "\n";
    for (auto &[_, a] : aOrder)
        cout << a + 1 << " ";
}