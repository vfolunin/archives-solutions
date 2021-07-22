#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int aLimit, bLimit, siteCount;
    if (!(cin >> aLimit >> bLimit >> siteCount))
        return 0;

    vector<int> itemCount(siteCount);
    vector<vector<int>> aCost(siteCount);

    for (int site = 0; site < siteCount; site++) {
        cin >> itemCount[site];

        aCost[site].resize(itemCount[site] + 1);
        for (int items = 1; items <= itemCount[site]; items++)
            cin >> aCost[site][items];

        for (int items = itemCount[site] - 1; items >= 0; items--) {
            int cost;
            cin >> cost;
            aCost[site][items] += cost;
        }
    }

    vector<vector<int>> cost(siteCount + 1, vector<int>(aLimit + 1, 1e9));
    vector<vector<int>> aChecked(siteCount + 1, vector<int>(aLimit + 1, -1));
    cost[0][0] = 0;

    for (int site = 1; site <= siteCount; site++) {
        for (int aItems = 0; aItems <= aLimit; aItems++) {
            for (int a = 0; a <= aItems && a <= itemCount[site - 1]; a++) {
                int candidateCost = cost[site - 1][aItems - a] + aCost[site - 1][a];
                if (cost[site][aItems] > candidateCost) {
                    cost[site][aItems] = candidateCost;
                    aChecked[site][aItems] = a;
                }
            }
        }
    }

    cout << cost[siteCount][aLimit] << "\n";

    vector<int> a;
    for (int site = siteCount, aItems = aLimit; site > 0; site--) {
        a.push_back(aChecked[site][aItems]);
        aItems -= aChecked[site][aItems];
    }
    reverse(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << (i + 1 < a.size() ? " " : "\n\n");

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}