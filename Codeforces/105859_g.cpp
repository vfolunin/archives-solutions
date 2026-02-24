#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int eventCount, limit;
    cin >> eventCount >> limit;

    vector<pair<int, int>> events(eventCount);
    for (auto &[amount, time] : events)
        cin >> time >> amount;

    sort(events.begin(), events.end());
    vector<int> used(24);
    int res = 0;

    for (auto &[amount, time] : events) {
        if (!used[time] && limit >= amount) {
            used[time] = 1;
            limit -= amount;
            res++;
        }
    }

    cout << res;
}