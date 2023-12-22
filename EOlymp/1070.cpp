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

    int segmentCount;
    cin >> segmentCount;

    vector<pair<int, int>> events;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({ l, 1 });
        events.push_back({ r, -1 });
    }

    sort(events.begin(), events.end());

    int sum = 0, res = 0;
    for (int i = 0; i < events.size(); i++) {
        if (i && sum)
            res += events[i].first - events[i - 1].first;
        sum += events[i].second;
    }

    cout << res;
}