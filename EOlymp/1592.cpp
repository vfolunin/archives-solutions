#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int peopleCount;
    if (!(cin >> peopleCount))
        return 0;

    vector<int> time(peopleCount);
    for (int &t : time)
        cin >> t;
    sort(time.begin(), time.end());

    int totalTime = 0;
    vector<pair<int, int>> pairs;
    while (time.size() > 3) {
        int &a = time[0];
        int &b = time[1];
        int &y = time[time.size() - 2];
        int &z = time[time.size() - 1];

        if (b + a + z + b <= y + a + z + a) {
            pairs.push_back({ a, b });
            pairs.push_back({ a, 0 });
            pairs.push_back({ y, z });
            pairs.push_back({ b, 0 });
            totalTime += b + a + z + b;
        } else {
            pairs.push_back({ a, y });
            pairs.push_back({ a, 0 });
            pairs.push_back({ a, z });
            pairs.push_back({ a, 0 });
            totalTime += y + a + z + a;
        }

        time.pop_back();
        time.pop_back();
    }

    if (time.size() == 1) {
        pairs.push_back({ time[0], 0 });
        totalTime += time[0];
    } else if (time.size() == 2) {
        pairs.push_back({ time[0], time[1] });
        totalTime += time[1];
    } else {
        pairs.push_back({ time[0], time[1] });
        pairs.push_back({ time[0], 0 });
        pairs.push_back({ time[0], time[2] });
        totalTime += time[0] + time[1] + time[2];
    }

    cout << totalTime << "\n";
    for (auto &[a, b] : pairs) {
        cout << a;
        if (b)
            cout << " " << b;
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}