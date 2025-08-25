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

    int friendCount;
    cin >> friendCount;

    vector<int> attendCount(86400);
    for (int i = 0; i < friendCount; i++) {
        int segmentCount;
        cin >> segmentCount;

        for (int j = 0; j < segmentCount; j++) {
            int l, r;
            cin >> l >> r;

            for (int k = l; k <= r; k++)
                attendCount[k]++;
        }
    }

    int maxAttendCount = *max_element(attendCount.begin(), attendCount.end());

    cout << maxAttendCount << "\n" << count(attendCount.begin(), attendCount.end(), maxAttendCount);
}