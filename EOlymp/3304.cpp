#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int eraCount, queryCount;
    cin >> eraCount >> queryCount;

    if (!eraCount && !queryCount)
        return 0;

    map<int, pair<string, int>> era;
    for (int i = 0; i < eraCount; i++) {
        string name;
        int eraYear, year;
        cin >> name >> eraYear >> year;

        era[year - eraYear + 1] = { name, year };
    }

    for (int i = 0; i < queryCount; i++) {
        int year;
        cin >> year;

        auto it = era.upper_bound(year);
        if (it == era.begin() || prev(it)->second.second < year) {
            cout << "Unknown\n";
            continue;
        }

        it--;
        cout << it->second.first << " " << year - it->first + 1 << "\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}