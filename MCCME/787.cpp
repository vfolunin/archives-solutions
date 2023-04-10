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

    int curDay, curHours, curMinutes;
    cin >> curDay >> curHours >> curMinutes;

    int curTime = (curDay - 1) * 24 * 60 + curHours * 60 + curMinutes;
    int nextTime = -1;

    int alarmsCount;
    cin >> alarmsCount;

    for (int i = 0; i < alarmsCount; i++) {
        int day, hours, minutes, cycleTime = 7 * 24 * 60;
        cin >> day >> hours >> minutes;
        if (day == 0) {
            day = curDay;
            cycleTime = 24 * 60;
        }

        int time = (day - 1) * 24 * 60 + hours * 60 + minutes;
        while (time < curTime)
            time += cycleTime;

        if (nextTime == -1 || time < nextTime)
            nextTime = time;
    }

    int nextDay = nextTime / (24 * 60) % 7 + 1;
    int nextHours = nextTime % (24 * 60) / 60;
    int nextMinutes = nextTime % 60;
    cout << nextDay << " " << nextHours << " " << nextMinutes;
}