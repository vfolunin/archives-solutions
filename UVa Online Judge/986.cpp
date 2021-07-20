#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int width, peaksNeeded, peakHeight;
    if (!(cin >> width >> peaksNeeded >> peakHeight))
        return 0;
    width *= 2;

    vector<vector<vector<vector<int>>>> ways(peaksNeeded + 1, vector<vector<vector<int>>>(width + 2, vector<vector<int>>(width + 2, vector<int>(2))));
    ways[0][1][1][1] = 1;
    
    for (int peaks = 0; peaks <= peaksNeeded; peaks++) {
        for (int x = 2; x <= width; x++) {
            for (int y = 0; y <= width; y++) {
                ways[peaks][x][y][0] += ways[peaks][x - 1][y + 1][0];
                if (y != peakHeight - 1)
                    ways[peaks][x][y][0] += ways[peaks][x - 1][y + 1][1];
                if (peaks && y == peakHeight - 1)
                    ways[peaks][x][y][0] += ways[peaks - 1][x - 1][y + 1][1];

                if (y) {
                    ways[peaks][x][y][1] += ways[peaks][x - 1][y - 1][0];
                    ways[peaks][x][y][1] += ways[peaks][x - 1][y - 1][1];
                }
            }
        }
    }

    cout << ways[peaksNeeded][width][0][0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}