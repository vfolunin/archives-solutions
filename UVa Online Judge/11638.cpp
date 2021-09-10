#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int interval, alarmTime;
    cin >> interval >> alarmTime;

    vector<int> threshold(4);
    for (int &t : threshold)
        cin >> t;

    int config, measureCount;
    cin >> config >> measureCount;

    vector<pair<int, int>> measures(measureCount);
    for (auto &[duration, temp] : measures)
        cin >> duration >> temp;

    int alarm = 0, time = 0;
    for (int i = 0; i < measureCount; i++) {
        auto &[duration, temp] = measures[i];

        time += duration;
        if (time < alarmTime)
            continue;
        alarmTime += interval;

        for (int bit = 0; bit < 4; bit++) {
            if (!(config & (1 << bit)))
                continue;
            if (config & (1 << (4 + bit)))
                alarm |= (temp > threshold[bit]) << bit;
            else
                alarm |= (temp < threshold[bit]) << bit;
        }
    }

    cout << "Case " << test << ":";
    for (int bit = 0; bit < 4; bit++)
        cout << (alarm & (1 << bit) ? " yes" : " no");
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}