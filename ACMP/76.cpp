#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int hours, minutes;
    char colon;
    cin >> hours >> colon >> minutes;

    return hours * 60 + minutes;
}

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

    int segmentCount;
    cin >> segmentCount;

    multiset<Event> events;
    for (int i = 0; i < segmentCount; i++) {
        events.insert({ readTime(), Event::BEGIN });
        events.insert({ readTime(), Event::END });
    }

    int cur = 0, res = 0;
    for (auto &[time, type] : events) {
        cur += type == Event::BEGIN ? 1 : -1;
        res = max(res, cur);
    }

    cout << res;
}