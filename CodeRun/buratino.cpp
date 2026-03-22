#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int h, m, s;
    char colon;
    cin >> h >> colon >> m >> colon >> s;
    return h * 60 * 60 + m * 60 + s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int workTimeCount;
    cin >> workTimeCount;

    map<int, int> workTimes;
    for (int i = 0; i < workTimeCount; i++) {
        int time = readTime(), workTime;
        cin >> workTime;
        workTimes[time] = workTime;
    }

    vector<int> res(48 * 60 * 60);
    for (int i = 9 * 60 * 60; i <= 18 * 60 * 60; i++) {
        res[i] = max(res[i], res[i - 1]);
        int workTime = prev(workTimes.upper_bound(i))->second;

        if (i + workTime <= 13 * 60 * 60 || 14 * 60 * 60 <= i)
            res[i + workTime] = max(res[i + workTime], res[i] + 1);
    }

    cout << res[18 * 60 * 60];
}