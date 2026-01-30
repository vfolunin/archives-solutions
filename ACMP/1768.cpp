#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Runner {
    inline static long long totalDist = 0;

    static long long ask(long long dist) {
        totalDist += dist;

        cout << "run " << dist << endl;

        long long ans;
        cin >> ans;

        return ans;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int l = 0, r = 1e9 + 1;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        long long laps = Runner::ask(m);

        if (laps < Runner::totalDist / m) {
            l = m;
        } else if (laps > Runner::totalDist / m) {
            r = m;
        } else {
            if (laps == Runner::ask((laps + 1) * m - Runner::totalDist))
                l = m;
            else
                r = m;
        }
    }

    cout << "ensure " << r << endl;
}