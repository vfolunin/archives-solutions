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

    int pushCount;
    cin >> pushCount;

    vector<int> pushes(pushCount);
    for (int &push : pushes)
        cin >> push;

    int curDirtiness = 0, curPushCount = 0, cleanupCount = 0;
    for (int day = 1, i = 0; day <= 365; day++) {
        if (curDirtiness + curPushCount >= 20) {
            curDirtiness = curPushCount = 0;
            cleanupCount++;
        }
        curDirtiness += curPushCount;
        if (i < pushes.size() && day == pushes[i]) {
            curPushCount++;
            i++;
        }
    }
    cleanupCount += (bool)curPushCount;

    cout << cleanupCount;
}