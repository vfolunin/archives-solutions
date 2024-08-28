#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, int wolfCount, double time) {
    long long wolfNeed = 0;
    for (int value : a)
        wolfNeed += ceil(value / time);
    return wolfNeed <= wolfCount;
}

bool solve() {
    int wolfCount, pigCount;
    cin >> wolfCount >> pigCount;

    if (!wolfCount && !pigCount)
        return 0;

    vector<int> a(pigCount);
    for (int &value : a)
        cin >> value;

    if (wolfCount < pigCount) {
        cout << "Impossible\n";
        return 1;
    }

    double l = 0, r = 1e18;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (can(a, wolfCount, m))
            r = m;
        else
            l = m;
    }

    cout << fixed << r << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}