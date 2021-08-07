#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Cistern {
    double base, height, width, depth;
};

double getVolume(vector<Cistern> &cisterns, double level) {
    double res = 0;
    for (auto &[b, h, w, d] : cisterns)
        if (b <= level)
            res += min(h, level - b) * w * d;
    return res;
}

void solve(int test) {
    int cisternCount;
    cin >> cisternCount;

    vector<Cistern> cisterns(cisternCount);
    double maxVolume = 0;
    for (auto &[b, h, w, d] : cisterns) {
        cin >> b >> h >> w >> d;
        maxVolume += h * w * d;
    }

    double volume;
    cin >> volume;

    double l = 0, r = 1e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (getVolume(cisterns, m) < volume)
            l = m;
        else
            r = m;
    }

    if (test)
        cout << "\n";
    if (volume > maxVolume) {
        cout << "OVERFLOW\n";
    } else {
        cout.precision(2);
        cout << fixed << l << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}