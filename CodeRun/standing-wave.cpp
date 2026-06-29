#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int l, r, delta;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int eventCount, queryCount;
    cin >> eventCount >> queryCount;

    vector<Event> events(eventCount);
    for (auto &[l, r, delta] : events)
        cin >> l >> r >> delta;

    for (int i = 0; i < queryCount; i++) {
        int x;
        cin >> x;

        int res = 0;
        for (auto &[l, r, delta] : events)
            if (l <= x && x <= r)
                res += delta * ((x - l) % 2 ? -1 : 1);

        cout << res << "\n";
    }
}