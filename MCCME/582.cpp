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
    
    int roadCount, laneCount;
    cin >> roadCount >> laneCount;

    vector<vector<long long>> ways(roadCount, vector<long long>(laneCount));
    fill(ways[0].begin(), ways[0].end(), 1);

    for (int road = 1; road < roadCount; road++) {
        for (int lane = 0; lane < laneCount; lane++) {
            for (int prevLane = 0; prevLane < lane; prevLane++)
                ways[road][lane] += 2 * ways[road - 1][prevLane];
            ways[road][lane] += ways[road - 1][lane];
        }
    }

    cout << ways[roadCount - 1][laneCount - 1];
}