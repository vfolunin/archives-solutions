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

    int size;
    cin >> size;

    multiset<pair<int, int>> counts;
    for (int i = 0; i < size; i++) {
        int count;
        cin >> count;
        counts.insert({ count, i + 1 });
    }

    vector<pair<int, int>> res;
    while (counts.size() > 1) {
        auto [countA, idA] = *prev(counts.end());
        counts.erase(prev(counts.end()));
        auto [countB, idB] = *prev(counts.end());
        counts.erase(prev(counts.end()));

        if (countA > 1)
            counts.insert({ countA - 1, idA });
        if (countB > 1)
            counts.insert({ countB - 1, idB });

        res.push_back({ idA, idB });
    }

    cout << res.size() << "\n";
    for (auto &[idA, idB] : res)
        cout << idA << " " << idB << "\n";
}