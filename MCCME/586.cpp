#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long balloonsNeed, long long time,
         vector<long long> &workTime, vector<long long> &balloonCount, vector<long long> &restTime) {
    long long balloons = 0;
    for (int i = 0; i < workTime.size() && balloons < balloonsNeed; i++) {
        long long cycleTime = workTime[i] * balloonCount[i] + restTime[i];
        long long cycles = time / cycleTime, remainingTime = time % cycleTime;
        balloons += cycles * balloonCount[i];
        balloons += min(balloonCount[i], remainingTime / workTime[i]);
    }
    return balloons >= balloonsNeed;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long balloonsNeed, size;
    cin >> balloonsNeed >> size;

    vector<long long> workTime(size), balloonCount(size), restTime(size);
    for (int i = 0; i < size; i++)
        cin >> workTime[i] >> balloonCount[i] >> restTime[i];

    long long l = -1, r = 1e10;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(balloonsNeed, m, workTime, balloonCount, restTime))
            r = m;
        else
            l = m;
    }

    cout << r << "\n";
    for (int i = 0; i < size; i++) {
        long long cycleTime = workTime[i] * balloonCount[i] + restTime[i];
        long long cycles = r / cycleTime, remTime = r % cycleTime;
        long long balloons = cycles * balloonCount[i] + min(balloonCount[i], remTime / workTime[i]);
        cout << min(balloonsNeed, balloons) << " ";
        balloonsNeed -= min(balloonsNeed, balloons);
    }
}