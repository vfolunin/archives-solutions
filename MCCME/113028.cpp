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

    int sidePaintAmount, paintAmount, cubeCount;
    cin >> sidePaintAmount >> paintAmount >> cubeCount;

    int cubePaintAmount = 6 * sidePaintAmount;
    int paintedCubeCount = min(paintAmount / cubePaintAmount, cubeCount);
    paintAmount -= paintedCubeCount * cubePaintAmount;
    int paintedSideCount = paintedCubeCount < cubeCount ? paintAmount / sidePaintAmount : 0;
    paintAmount -= paintedSideCount * sidePaintAmount;

    cout << paintedCubeCount << "\n" << paintedSideCount << "\n" << paintAmount;
}