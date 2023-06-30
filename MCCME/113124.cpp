#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int x;
    enum { BEGIN, END } type;

    bool operator < (const Event &that) const {
        if (x != that.x)
            return x < that.x;
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
        events.push_back({ l, Event::BEGIN });
        events.push_back({ r, Event::END });
    }

    sort(events.begin(), events.end());

    vector<pair<int, int>> res;
    int curSegments = 0;

    for (auto &[x, type] : events) {
        if (type == Event::BEGIN) {
            if (!curSegments)
                res.push_back({ x, x });
            curSegments++;
        } else {
            curSegments--;
            if (!curSegments)
                res.back().second = x;
        }
    }

    cout << res.size() << "\n";
    for (auto &[l, r] : res)
        cout << l << " " << r << "\n";
}