#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int hours, minutes;
    cin >> hours >> minutes;

    return hours * 60 + minutes;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int curTime = readTime();

    int stationCount;
    cin >> stationCount;

    int res = 24 * 60;
    for (int i = 0; i < stationCount; i++) {
        int travelTime, trainCount;
        cin >> travelTime >> trainCount;

        for (int j = 0; j < trainCount; j++) {
            int arrivalTime = (readTime() + travelTime) % (24 * 60);
            if (arrivalTime < curTime)
                arrivalTime += 24 * 60;
            res = min(res, arrivalTime - curTime);
        }
    }

    cout << res;
}