#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool solve() {
    int cubeCount;
    cin >> cubeCount;

    if (cubeCount < 0)
        return 0;

    vector<vector<long long>> ways(cubeCount + 1, vector<long long>(cubeCount + 1));
    ways[0][0] = 1;
    for (int cubes = 1; cubes <= cubeCount; cubes++) {
        for (int lastCubes = 1; lastCubes <= cubes; lastCubes++)
            for (int prevCubes = 1; prevCubes <= lastCubes; prevCubes++)
                ways[cubes][lastCubes] += ways[cubes - lastCubes][prevCubes];
        ways[cubes][cubes] = 1;
    }

    cout << cubeCount << " => " << accumulate(ways[cubeCount].begin(), ways[cubeCount].end(), 0LL) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}