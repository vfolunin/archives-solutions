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

    int missionCount, targetPoints;
    cin >> missionCount >> targetPoints;

    vector<int> minTime(2e4, 1e9);
    minTime[0] = 0;

    for (int i = 0; i < missionCount; i++) {
        int missionPoints, missionTime;
        cin >> missionPoints >> missionTime;
        
        for (int points = minTime.size() - 1; points >= missionPoints; points--)
            minTime[points] = min(minTime[points], minTime[points - missionPoints] + missionTime);
    }

    int res = *min_element(minTime.begin() + targetPoints, minTime.end());

    cout << (res < 1e9 ? res : -1);
}