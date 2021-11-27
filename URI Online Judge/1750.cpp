#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dist(int t1, int t2) {
    int dt = abs(t1 - t2);
    return min(dt, 24 - dt);
}

bool solve() {
    int timezoneCount;
    if (!(cin >> timezoneCount))
        return 0;

    vector<int> timezones(timezoneCount);
    for (int &t : timezones)
        cin >> t;

    sort(timezones.begin(), timezones.end());

    int sum1 = 0;
    for (int i = 0; i < timezoneCount; i += 2)
        sum1 += dist(timezones[i], timezones[i + 1]);

    int sum2 = 0;
    for (int i = 1; i < timezoneCount; i += 2)
        sum2 += dist(timezones[i], timezones[(i + 1) % timezoneCount]);

    cout << min(sum1, sum2) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}