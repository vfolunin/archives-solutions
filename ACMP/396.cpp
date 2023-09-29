#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int x;
    enum { BEGIN, POINT, END } type;
    int index = -1;

    bool operator < (const Event &that) const {
        if (x != that.x)
            return x < that.x;
        return type < that.type;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int segmentCount, pointCount;
    cin >> segmentCount >> pointCount;

    vector<Event> events;

    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        if (l > r)
            swap(l, r);

        events.push_back({ l, Event::BEGIN });
        events.push_back({ r, Event::END });
    }

    for (int i = 0; i < pointCount; i++) {
        int x;
        cin >> x;

        events.push_back({ x, Event::POINT, i });
    }

    sort(events.begin(), events.end());

    vector<int> res(pointCount);
    int segments = 0;
    for (auto &[x, type, index] : events) {
        if (type == Event::BEGIN)
            segments++;
        else if (type == Event::END)
            segments--;
        else
            res[index] = segments;
    }

    for (int value : res)
        cout << value << " ";
}