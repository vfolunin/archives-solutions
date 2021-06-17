#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int x, y1, y2, delta;

    bool operator < (const Event &that) const {
        return x < that.x;
    }
};

bool solve(int test) {
    int rectCount;
    cin >> rectCount;

    if (!rectCount)
        return 0;

    vector<Event> events;
    for (int i = 0; i < rectCount; i++) {
        double x, y, r;
        cin >> x >> y >> r;

        int x1 = round((x - r) * 100), x2 = round((x + r) * 100);
        int y1 = round((y - r) * 100) + 20000, y2 = round((y + r) * 100) + 20000;

        events.push_back({ x1, y1, y2, 1 });
        events.push_back({ x2, y1, y2, -1 });
    }

    sort(events.begin(), events.end());
    vector<int> line(60001);

    double res = 0;
    for (int i = 0; i < events.size(); i++) {
        if (i) {
            for (int y = 0; y < line.size(); y++)
                if (line[y])
                    res += events[i].x - events[i - 1].x;
        }
        for (int y = events[i].y1; y < events[i].y2; y++)
            line[y] += events[i].delta;
    }

    cout.precision(2);
    cout << test << " " << fixed << res / 10000.0 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}