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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int width, queryCount;
    cin >> width >> queryCount;

    set<pair<int, int>> segments = { { 0, width } };
    multiset<int> lengths = { width };

    for (int i = 0; i < queryCount; i++) {
        int x;
        cin >> x;

        auto [from, width] = *--segments.upper_bound({ x, 0 });
        segments.erase({ from, width });
        lengths.erase(lengths.find(width));

        segments.insert({ from, x - from });
        lengths.insert(x - from);

        segments.insert({ x, width - (x - from) });
        lengths.insert(width - (x - from));

        cout << *lengths.rbegin() << " ";
    }
}