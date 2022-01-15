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

    int startTime, finishTime, busCount;
    cin >> startTime >> finishTime >> busCount;

    vector<int> walkTime(busCount + 1);
    for (int &time : walkTime)
        cin >> time;

    vector<int> rideTime(busCount);
    for (int &time : rideTime)
        cin >> time;

    vector<int> interval(busCount);
    for (int &time : interval)
        cin >> time;

    int time = startTime;
    for (int i = 0; i < busCount; i++) {
        time += walkTime[i];
        time = (time + interval[i] - 1) / interval[i] * interval[i];
        time += rideTime[i];
    }
    time += walkTime.back();

    cout << (time <= finishTime ? "yes" : "no");
}