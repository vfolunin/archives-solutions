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

    map<int, multiset<int>> events;
    while (1) {
        int l, h, r;
        if (!(cin >> l >> h >> r))
            break;
        events[l].insert(h);
        events[r].insert(-h);
    }

    int prevHeight = 0;
    multiset<int> curHeights = { 0 };
    vector<int> res;

    for (auto &[x, heights] : events) {
        for (int h : heights) {
            if (h > 0)
                curHeights.insert(h);
            else
                curHeights.erase(curHeights.find(-h));
        }
        if (*curHeights.rbegin() != prevHeight) {
            res.push_back(x);
            res.push_back(*curHeights.rbegin());
        }
        prevHeight = *curHeights.rbegin();
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
}