#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int classesNeeded, vector<int> &classTime, vector<int> &classCount, vector<int> &skipTime, int time) {
    int classes = 0;

    for (int i = 0; i < classTime.size(); i++) {
        int periodTime = classTime[i] * classCount[i] + skipTime[i];
        int periodCount = time / periodTime;
        classes += classCount[i] * periodCount;

        int remainingTime = time % periodTime;
        classes += min(remainingTime / classTime[i], classCount[i]);
    }

    return classes >= classesNeeded;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, classesNeeded;
    cin >> size >> classesNeeded;

    vector<int> classTime(size), classCount(size), skipTime(size);
    for (int i = 0; i < size; i++)
        cin >> classTime[i] >> classCount[i] >> skipTime[i];

    int l = -1, r = 1;
    while (!can(classesNeeded, classTime, classCount, skipTime, r))
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(classesNeeded, classTime, classCount, skipTime, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}