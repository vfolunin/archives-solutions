#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    enum { BEGIN, POINT, END } type;
    int coord, index;

    bool operator < (const Event &that) const {
        if (coord != that.coord)
            return coord < that.coord;
        return type < that.type;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int width, segmentCount, pointCount;
    cin >> width >> segmentCount >> pointCount;

    vector<Event> events;

    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({ Event::BEGIN, l, 0 });
        events.push_back({ Event::END, r, 0 });
    }

    for (int i = 0; i < pointCount; i++) {
        int x;
        cin >> x;
        events.push_back({ Event::POINT, x, i });
    }

    sort(events.begin(), events.end());

    vector<int> res(pointCount);
    int curCount = 0;

    for (auto &[type, coord, index] : events) {
        if (type == Event::BEGIN)
            curCount++;
        else if (type == Event::END)
            curCount--;
        else
            res[index] = curCount;
    }

    for (int value : res)
        cout << value << "\n";
}