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

int readTime() {
    int h, m;
    cin >> h >> m;
    return h * 60 + m;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int ticketOfficeCount;
    cin >> ticketOfficeCount;

    vector<Event> events;

    for (int i = 0; i < ticketOfficeCount; i++) {
        int t1 = readTime(), t2 = readTime();
        if (t1 == t2) {
            events.push_back({ 0, Event::BEGIN });
            events.push_back({ 24 * 60, Event::END });
        } else if (t1 < t2) {
            events.push_back({ t1, Event::BEGIN });
            events.push_back({ t2, Event::END });
        } else {
            events.push_back({ t1, Event::BEGIN });
            events.push_back({ 24 * 60, Event::END });
            events.push_back({ 0, Event::BEGIN });
            events.push_back({ t2, Event::END });
        }
    }

    sort(events.begin(), events.end());

    int prevTime = 0, segmentCount = 0, res = 0;
    for (auto &[time, type] : events) {
        if (segmentCount == ticketOfficeCount)
            res += time - prevTime;

        if (type == Event::BEGIN)
            segmentCount++;
        else
            segmentCount--;

        prevTime = time;
    }

    cout << res;
}