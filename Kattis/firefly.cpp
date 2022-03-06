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

    int segmentCount, width;
    cin >> segmentCount >> width;

    vector<int> delta(width);
    for (int i = 0; i < segmentCount; i++) {
        int coord;
        cin >> coord;

        if (i % 2 == 0) {
            delta[0]++;
            delta[coord]--;
        } else {
            delta[width - coord]++;
        }
    }

    int curSegments = 0, minSegments = 1e9, minSegmentsWays = 0;
    for (int d : delta) {
        curSegments += d;
        if (minSegments > curSegments) {
            minSegments = curSegments;
            minSegmentsWays = 1;
        } else if (minSegments == curSegments) {
            minSegmentsWays++;
        }
    }

    cout << minSegments << " " << minSegmentsWays;
}