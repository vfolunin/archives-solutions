#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int coord;
    enum { END, BEGIN } type;
    int index;

    bool operator < (const Event &that) const {
        if (coord != that.coord)
            return coord < that.coord;
        return type < that.type;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int blockCount, w, h;
    cin >> blockCount >> w >> h;

    int totalArea = w * h;

    vector<int> area;
    vector<Event> events;
    for (int i = 0; i < blockCount; i++) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        area.push_back((x2 - x1) * (y2 - y1));
        events.push_back({ z1, Event::BEGIN, i });
        events.push_back({ z2, Event::END, i });
    }

    sort(events.begin(), events.end());

    set<int> curSet, resSet;
    int curArea = 0;

    for (auto &[coord, type, index] : events) {
        if (type == Event::BEGIN) {
            curArea += area[index];
            curSet.insert(index);
        } else {
            curArea -= area[index];
            curSet.erase(index);
        }

        if (curArea == totalArea && (resSet.empty() || resSet.size() > curSet.size()))
            resSet = curSet;
    }
    
    if (!resSet.empty()) {
        cout << "YES\n";
        cout << resSet.size() << "\n";
        for (int i : resSet)
            cout << i + 1 << " ";
    } else {
        cout << "NO";
    }
}