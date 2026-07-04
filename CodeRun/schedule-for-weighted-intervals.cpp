#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Interval {
    double l, r, weight;

    bool operator < (const Interval &that) const {
        return r < that.r;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int intervalCount;
    cin >> intervalCount;

    vector<Interval> intervals(intervalCount);
    for (auto &[l, r, weight] : intervals)
        cin >> l >> r >> weight;

    sort(intervals.begin(), intervals.end());

    map<double, double> sumTo;
    sumTo[-1e100] = 0;

    for (auto &[l, r, weight] : intervals)
        sumTo[r] = max(prev(sumTo.end())->second, prev(sumTo.upper_bound(l))->second + weight);
    
    cout << fixed << prev(sumTo.end())->second;
}