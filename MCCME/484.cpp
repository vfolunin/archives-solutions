#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

struct Event {
    enum { BEGIN, END } type;
    int index;

    bool operator < (const Event &that) const {
        return type < that.type;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int segmentCount;
    cin >> segmentCount;

    map<int, vector<Event>> events;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        if (l + 5 <= r) {
            events[l].push_back({ Event::BEGIN, i });
            events[r - 5].push_back({ Event::END, i });
        }
    }

    unordered_set<int> segments;
    int res = 0, resTime1 = 1e9, resTime2 = 1e9 + 5;

    for (auto &[time1, events1] : events) {
        for (auto &[type1, index1] : events1)
            if (type1 == Event::BEGIN)
                segments.insert(index1);

        if (res < segments.size()) {
            res = segments.size();
            resTime1 = time1;
            resTime2 = 1e9;
        }

        int delta = 0;
        for (auto it = events.upper_bound(time1); it != events.end(); it++) {
            auto &[time2, events2] = *it;

            for (auto &[type2, index2] : events2)
                delta += type2 == Event::BEGIN;

            if (time1 + 5 <= time2 && res < segments.size() + delta) {
                res = segments.size() + delta;
                resTime1 = time1;
                resTime2 = time2;
            }

            for (auto &[type2, index2] : events2)
                delta -= type2 == Event::END && !segments.count(index2);
        }

        for (auto &[type1, index1] : events1)
            if (type1 == Event::END)
                segments.erase(index1);
    }

    cout << res << " " << resTime1 << " " << resTime2;
}