#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int stationCount, sumLimit;
    cin >> stationCount >> sumLimit;

    vector<int> stations(stationCount);
    for (int &s : stations)
        cin >> s;

    int maxStations = 0, bestSum = 0, sum = 0;
    for (int l = 0, r = 0; l < stationCount; l++) {
        while (r < stationCount && sum + stations[r] <= sumLimit) {
            sum += stations[r];
            r++;
        }
        if (maxStations < r - l || maxStations == r - l && bestSum > sum) {
            maxStations = r - l;
            bestSum = sum;
        }
        sum -= stations[l];
    }

    cout << bestSum << " " << maxStations << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}