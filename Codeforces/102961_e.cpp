#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int time;
    enum { OUT, IN } type;

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        return type < that.type;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int eventCount;
    cin >> eventCount;

    vector<Event> events;
    for (int i = 0; i < eventCount; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({ l, Event::IN });
        events.push_back({ r, Event::OUT });
    }
    sort(events.begin(), events.end());

    int res = 0, cur = 0;
    for (auto &[_, type] : events) {
        if (type == Event::IN)
            cur++;
        else
            cur--;
        res = max(res, cur);
    }

    cout << res;
}