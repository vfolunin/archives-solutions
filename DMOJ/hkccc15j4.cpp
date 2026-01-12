#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int coord;
    enum { BEGIN, END } type;

    bool operator < (const Event &that) const {
        if (coord != that.coord)
            return coord < that.coord;
        return type < that.type;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int length, segmentCount;
    cin >> length >> segmentCount;

    vector<Event> events;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        events.push_back({ l, Event::BEGIN });
        events.push_back({ r, Event::END });
    }

    sort(events.begin(), events.end());

    int curSegmentCount = 0, res = 0;
    for (int i = 0; i < events.size(); i++) {
        if (!curSegmentCount)
            res = max(res, events[i].coord - (i ? events[i - 1].coord : 0));
        curSegmentCount += events[i].type == Event::BEGIN ? 1 : -1;
    }
    res = max(res, length - events.back().coord);

    cout << res;
}