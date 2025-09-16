#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int rec(vector<vector<pair<int, int>>> &buses, int i, unordered_set<int> ids, int cost) {
    if (i == buses.size())
        return cost;

    int res = 1e9;
    for (auto &[id, price] : buses[i]) {
        if (ids.count(id))
            continue;

        ids.insert(id);
        res = min(res, rec(buses, i + 1, ids, cost + price));
        ids.erase(id);
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int stopCount;
    cin >> stopCount;
    stopCount--;

    vector<vector<pair<int, int>>> buses(stopCount);
    for (int i = 0; i < stopCount; i++) {
        int busCount;
        cin >> busCount;

        buses[i].resize(busCount);
        for (auto &[id, price] : buses[i])
            cin >> id >> price;
    }

    unordered_set<int> ids;
    int res = rec(buses, 0, ids, 0);

    if (res != 1e9)
        cout << res;
    else
        cout << "CAN MEH?";
}