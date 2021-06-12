#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string name;
    if (!(cin >> name))
        return 0;

    int floorCount, holeCount;
    cin >> floorCount >> holeCount;

    vector<int> time(holeCount);
    for (int floor = 0; floor < floorCount - 1; floor++) {
        vector<int> nextTime(holeCount, 1e9);
        for (int i = 0; i < holeCount; i++) {
            for (int j = 0; j < holeCount; j++) {
                int t;
                cin >> t;
                nextTime[j] = min(nextTime[j], time[i] + t + 2);
            }
        }
        time.swap(nextTime);
    }

    cout << name << "\n";
    cout << *min_element(time.begin(), time.end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}