#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    map<int, int> count;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;
            count[value]++;
        }
    }

    set<int> counts;
    for (auto &[v, k] : count)
        counts.insert(k);

    int secondCount = *prev(prev(counts.end()));
    for (auto &[v, k] : count)
        if (k == secondCount)
            cout << v << " ";

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}