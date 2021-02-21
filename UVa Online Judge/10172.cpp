#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int platformCount, vehicleLimit, platformLimit;
    cin >> platformCount >> vehicleLimit >> platformLimit;

    vector<deque<int>> platform(platformCount);
    int totalCargoCount = 0;

    for (deque<int> &p : platform) {
        int platformCargoCount;
        cin >> platformCargoCount;
        totalCargoCount += platformCargoCount;

        p.resize(platformCargoCount);
        for (int &x : p)
            cin >> x;
    }

    int time = 0, curPlatform = 0;
    vector<int> vehicle;

    while (totalCargoCount) {
        while (!vehicle.empty() && platform[curPlatform].size() < platformLimit) {
            if (vehicle.back() == curPlatform + 1)
                totalCargoCount--;
            else
                platform[curPlatform].push_back(vehicle.back());
            vehicle.pop_back();
            time++;
        }
        while (!vehicle.empty() && vehicle.back() == curPlatform + 1) {
            totalCargoCount--;
            vehicle.pop_back();
            time++;
        }

        while (vehicle.size() < vehicleLimit && !platform[curPlatform].empty()) {
            vehicle.push_back(platform[curPlatform].front());
            platform[curPlatform].pop_front();
            time++;
        }

        if (totalCargoCount) {
            curPlatform = (curPlatform + 1) % platformCount;
            time += 2;
        }
    }

    cout << time << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}