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

    int size, opCount;
    cin >> size >> opCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    multiset<pair<int, int>> pairs;
    for (int i = 0; i < size; i++)
        pairs.insert({ a[i], i });

    vector<pair<int, int>> res;
    for (int i = 0; i < opCount; i++) {
        auto [a, ai] = *pairs.begin();
        auto [b, bi] = *prev(pairs.end());

        if (a == b)
            break;

        pairs.erase(pairs.begin());
        pairs.erase(prev(pairs.end()));

        pairs.insert({ a + 1, ai });
        pairs.insert({ b - 1, bi });
        res.push_back({ bi, ai });
    }

    cout << prev(pairs.end())->first - pairs.begin()->first << " " << res.size() << "\n";
    for (auto &[ai, bi] : res)
        cout << ai + 1 << " " << bi + 1 << "\n";
}