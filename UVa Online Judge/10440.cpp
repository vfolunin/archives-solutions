#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int capacity, travelTime, carCount;
    cin >> capacity >> travelTime >> carCount;

    vector<int> minTime(carCount);
    vector<int> minTravelCount(carCount);

    for (int i = 0; i < carCount; i++) {
        int carTime;
        cin >> carTime;

        minTime[i] = 1e9;
        for (int takenCarCount = 1; takenCarCount <= capacity && takenCarCount <= i + 1; takenCarCount++) {
            int candidateTime = carTime, candidateTravelCount = 1;
            if (i + 1 - takenCarCount) {
                candidateTime = max(candidateTime, minTime[i - takenCarCount] + travelTime);
                candidateTravelCount += minTravelCount[i - takenCarCount];
            }
            candidateTime += travelTime;

            if (minTime[i] > candidateTime ||
                minTime[i] == candidateTime && minTravelCount[i] > candidateTravelCount) {
                minTime[i] = candidateTime;
                minTravelCount[i] = candidateTravelCount;
            }
        }
    }

    cout << minTime.back() << " " << minTravelCount.back() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}