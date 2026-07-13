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

    vector<pair<int, int>> pairs(size);
    for (int i = 0; i < pairs.size(); i++) {
        cin >> pairs[i].first;
        pairs[i].second = i;
    }

    sort(pairs.begin(), pairs.end());

    int res, resDist = -1;
    for (int i = 0; i < pairs.size(); i++) {
        int dist = 2e9;
        if (i)
            dist = min(dist, pairs[i].first - pairs[i - 1].first);
        if (i + 1 < pairs.size())
            dist = min(dist, pairs[i + 1].first - pairs[i].first);

        if (resDist < dist || resDist == dist && res > pairs[i].second) {
            resDist = dist;
            res = pairs[i].second;
        }
    }

    cout << res + 1;
}