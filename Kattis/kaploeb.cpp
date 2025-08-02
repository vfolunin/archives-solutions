#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int recordCount, lapCount, participantCount;
    cin >> recordCount >> lapCount >> participantCount;

    unordered_map<int, int> laps, time;
    for (int i = 0; i < recordCount; i++) {
        int participant, minutes, seconds;
        char dot;
        cin >> participant >> minutes >> dot >> seconds;

        laps[participant]++;
        time[participant] += minutes * 60 + seconds;
    }

    vector<pair<int, int>> pairs;
    for (auto &[participant, laps] : laps)
        if (laps == lapCount)
            pairs.push_back({ time[participant], participant });

    sort(pairs.begin(), pairs.end());

    for (auto &[time, participant] : pairs)
        cout << participant << "\n";
}