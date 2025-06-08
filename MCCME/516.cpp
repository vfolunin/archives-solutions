#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int coord, index;
    enum { END, BEGIN } type;

    bool operator < (const Event &that) const {
        if (coord != that.coord)
            return coord < that.coord;
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
        int l, r;
        cin >> l >> r;

        events.push_back({ l, i, Event::BEGIN });
        events.push_back({ r, i, Event::END });
    }
    sort(events.begin(), events.end());

    unordered_set<int> opened;
    long long resDist = 1e18;
    pair<int, int> res;

    for (int i = 0; i < events.size(); i++) {
        if (events[i].type == Event::BEGIN) {
            opened.insert(events[i].index);
            continue;
        }

        opened.erase(events[i].index);
        if (events[i - 1].type == Event::END || opened.empty())
            continue;

        int dist = events[i].coord - events[i - 1].coord;
        if (resDist > dist) {
            resDist = dist;
            if (events[i - 1].index != events[i].index)
                res = { events[i - 1].index, events[i].index };
            else
                res = { *opened.begin(), events[i].index };
        }
    }

    if (resDist != 1e18)
        cout << res.first + 1 << " " << res.second + 1;
    else
        cout << 0;
}