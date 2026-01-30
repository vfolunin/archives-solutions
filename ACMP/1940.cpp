#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getCount(vector<int> &addTime, vector<int> &duplicateTime, int time) {
    long long count = 0;
    for (int i = 0; i < addTime.size() && count <= 1e9; i++) {
        if (time >= addTime[i] + duplicateTime[i])
            count += 1LL << min(time - addTime[i] - duplicateTime[i] + 1, 31);
        else if (time >= addTime[i])
            count++;
    }
    return count;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size, targetCount;
    cin >> size >> targetCount;

    vector<int> addTime(size);
    for (int &time : addTime)
        cin >> time;

    vector<int> duplicateTime(size);
    for (int &time : duplicateTime)
        cin >> time;

    int l = 0, r = 1;
    while (getCount(addTime, duplicateTime, r) < targetCount)
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (getCount(addTime, duplicateTime, m) < targetCount)
            l = m;
        else
            r = m;
    }

    cout << (getCount(addTime, duplicateTime, r) == targetCount ? r : -1);
}