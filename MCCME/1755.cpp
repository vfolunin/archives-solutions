#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int time;
    enum { END, BEGIN } type;

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        return type < that.type;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int segmentCount;
    cin >> segmentCount;

    vector<Event> events;
    for (int i = 0; i < segmentCount; i++) {
        int time, duration;
        cin >> time >> duration;
        events.push_back({ time, Event::BEGIN });
        events.push_back({ time + duration, Event::END });
    }

    sort(events.begin(), events.end());

    int curSegments = 0, res = 0;
    for (auto &[time, type] : events) {
        if (type == Event::BEGIN)
            curSegments++;
        else
            curSegments--;
        res = max(res, curSegments);
    }

    cout << res;
}