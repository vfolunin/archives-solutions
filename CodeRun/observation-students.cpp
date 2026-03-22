#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int x;
    enum { L, R } type;

    bool operator < (const Event &that) const {
        if (x != that.x)
            return x < that.x;
        return type < that.type;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int width, segmentCount;
    cin >> width >> segmentCount;

    vector<Event> events;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({ l, Event::L });
        events.push_back({ r, Event::R });
    }

    sort(events.begin(), events.end());

    int uncoveredWidth = 0, curSegments = 0, lastX = -1;
    for (auto &[x, type] : events) {
        if (!curSegments)
            uncoveredWidth += x - 1 - lastX;
        curSegments += type == Event::L;
        curSegments -= type == Event::R;
        lastX = x;
    }
    uncoveredWidth += width - 1 - lastX;

    cout << uncoveredWidth;
}