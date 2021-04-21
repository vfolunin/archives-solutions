#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int teamCount, tableCount;
    cin >> teamCount >> tableCount;

    if (!teamCount && !tableCount)
        return 0;

    set<pair<int, int>> teams;
    for (int i = 0; i < teamCount; i++) {
        int x;
        cin >> x;
        teams.insert({ x, i });
    }

    set<pair<int, int>> tables;
    for (int i = 0; i < tableCount; i++) {
        int x;
        cin >> x;
        tables.insert({ x, i });
    }

    vector<vector<int>> ans(teamCount);
    while (!teams.empty()) {
        auto [teamSize, team] = *--teams.end();
        teams.erase(--teams.end());

        vector<pair<int, int>> updatedTables;

        for (int i = 0; i < teamSize; i++) {
            if (tables.empty()) {
                cout << "0\n";
                return 1;
            }

            auto [tableSize, table] = *--tables.end();
            tables.erase(--tables.end());

            ans[team].push_back(table);

            if (tableSize > 1)
                updatedTables.push_back({ tableSize - 1, table });
        }

        tables.insert(updatedTables.begin(), updatedTables.end());
    }

    cout << "1\n";
    for (auto &tables : ans) {
        sort(tables.begin(), tables.end());
        for (int i = 0; i < tables.size(); i++)
            cout << tables[i] + 1 << (i + 1 < tables.size() ? ' ' : '\n');
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}