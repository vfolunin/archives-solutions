#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cubeCount;
    cin >> cubeCount;

    vector<vector<long long>> ways(cubeCount + 1, vector<long long>(cubeCount + 1));
    for (int cubes = 1; cubes <= cubeCount; cubes++) {
        for (int lastCubes = 1; lastCubes < cubes; lastCubes++)
            for (int prevCubes = 1; prevCubes < lastCubes; prevCubes++)
                ways[cubes][lastCubes] += ways[cubes - lastCubes][prevCubes];
        ways[cubes][cubes] = 1;
    }

    cout << accumulate(ways[cubeCount].begin(), ways[cubeCount].end(), 0LL);
}