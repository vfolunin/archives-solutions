#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int h, m;
    char colon;
    cin >> h >> colon >> m;
    return h * 60 + m;
}

struct Event {
    int time;
    enum { IN, OUT } type;
    int v;

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        return type < that.type;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;
    vertexCount++;

    vector<Event> events;
    vector<int> balance(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a;
        cin >> a;
        int ta = readTime();
        int b;
        cin >> b;
        int tb = readTime();

        if (ta > tb) {
            events.push_back({ 0, Event::OUT, 0 });
            events.push_back({ 24 * 60, Event::IN, 0 });
        }

        events.push_back({ ta, Event::OUT, a });
        events.push_back({ tb, Event::IN, b });

        balance[a]--;
        balance[b]++;
    }

    if (count(balance.begin(), balance.end(), 0) != vertexCount) {
        cout << -1;
        return 0;
    }

    sort(events.begin(), events.end());

    vector<int> busCount(vertexCount);
    int res = 0;

    for (auto &[time, type, v] : events) {
        if (type == Event::OUT) {
            if (busCount[v])
                busCount[v]--;
            else
                res++;
        } else {
            busCount[v]++;
        }
    }

    cout << res;
}