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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int segmentCount, segmentSize;
    cin >> segmentCount >> segmentSize;

    vector<Event> events;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({ l - segmentSize, Event::BEGIN });
        events.push_back({ r, Event::END });
    }
    sort(events.begin(), events.end());

    int curSegmentCount = 0, maxSegmentCount = 0;
    for (auto &[_, type] : events) {
        if (type == Event::BEGIN)
            curSegmentCount++;
        else
            curSegmentCount--;
        maxSegmentCount = max(maxSegmentCount, curSegmentCount);
    }

    cout << maxSegmentCount;
}