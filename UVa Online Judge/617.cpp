#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct TrafficLight {
    double coord, green, yellow, red;

    bool isRed(double speed) {
        double time = coord * 3600 / speed;
        return fmod(time, green + yellow + red) >= green + yellow;
    }
};

bool solve(int test) {
    int trafficLightsCount;
    cin >> trafficLightsCount;

    if (trafficLightsCount == -1)
        return 0;

    vector<TrafficLight> trafficLights(trafficLightsCount);
    for (auto &[coord, green, yellow, red] : trafficLights)
        cin >> coord >> green >> yellow >> red;

    vector<pair<int, int>> res;
    for (int speed = 30; speed <= 60; speed++) {
        bool ok = 1;
        for (int i = 0; ok && i < trafficLightsCount; i++)
            ok &= !trafficLights[i].isRed(speed);

        if (ok) {
            if (res.empty() || res.back().second + 1 < speed)
                res.push_back({ speed, speed });
            else
                res.back().second++;
        }
    }

    cout << "Case " << test << ": ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first;
        if (res[i].first != res[i].second)
            cout << "-" << res[i].second;
        cout << (i + 1 < res.size() ? ", " : "\n");
    }
    if (res.empty())
        cout << "No acceptable speeds.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}