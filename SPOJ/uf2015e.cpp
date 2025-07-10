#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int time;
    enum { BEGIN, END } type;

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        return type < that.type;
    }
};

void solve() {
    int segmentCount;
    cin >> segmentCount;

    vector<Event> events;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        events.push_back({ l, Event::BEGIN });
        events.push_back({ r, Event::END });
    }

    sort(events.begin(), events.end());

    int curSegments = 0, maxSegments = 0;
    for (auto &[time, type] : events) {
        curSegments += type == Event::BEGIN ? 1 : -1;
        maxSegments = max(maxSegments, curSegments);
    }

    cout << maxSegments << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}