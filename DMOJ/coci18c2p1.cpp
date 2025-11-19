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

    vector<pair<int, int>> events;
    for (int team = 0; team < 2; team++) {
        int eventCount;
        cin >> eventCount;

        for (int i = 0; i < eventCount; i++) {
            int time;
            cin >> time;

            events.push_back({ time, team });
        }
    }

    sort(events.begin(), events.end());
    
    int res1 = 0, res2 = 0, winning = -1;
    vector<int> score(2);
    for (auto &[time, team] : events) {
        res1 += time <= 2 * 12 * 60;

        score[team]++;

        int newWinning = -1;
        if (score[0] > score[1])
            newWinning = 0;
        else if (score[0] < score[1])
            newWinning = 1;

        if (newWinning != -1) {
            res2 += winning != -1 && winning != newWinning;
            winning = newWinning;
        }
    }
    
    cout << res1 << "\n" << res2;
}