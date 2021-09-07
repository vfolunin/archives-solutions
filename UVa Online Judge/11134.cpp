#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Limit {
    int index, l, r;

    bool operator < (const Limit &that) const {
        if (l != that.l)
            return l < that.l;
        return r < that.r;
    }
};

struct Comparator {
    bool operator ()(const Limit &a, const Limit &b) const {
        if (a.r != b.r)
            return a.r < b.r;
        return a.index < b.index;
    }
};

vector<int> getCoords(vector<Limit> &limit) {
    sort(limit.begin(), limit.end());

    set<Limit, Comparator> curLimits;
    vector<int> res(limit.size());

    for (int x = 1, i = 0; x <= limit.size(); x++) {
        while (i < limit.size() && limit[i].l == x) {
            curLimits.insert(limit[i]);
            i++;
        }

        if (curLimits.empty() || x > curLimits.begin()->r)
            return {};

        res[curLimits.begin()->index] = x;
        curLimits.erase(curLimits.begin());
    }

    return res;
}

bool solve() {
    int rookCount;
    cin >> rookCount;

    if (!rookCount)
        return 0;

    vector<Limit> xLimit(rookCount), yLimit(rookCount);
    for (int i = 0; i < rookCount; i++) {
        cin >> xLimit[i].l >> yLimit[i].l >> xLimit[i].r >> yLimit[i].r;
        xLimit[i].index = yLimit[i].index = i;
    }

    vector<int> x = getCoords(xLimit), y = getCoords(yLimit);

    if (x.empty() || y.empty()) {
        cout << "Impossible\n";
    } else {
        for (int i = 0; i < rookCount; i++)
            cout << x[i] << " " << y[i] << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}