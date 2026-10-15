#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int getLastRegion(int regionCount, int step) {
    vector<int> activeRegions(regionCount);
    for (int i = 0; i < regionCount; i++)
        activeRegions[i] = i;

    int regionIndex = 0;
    do {
        activeRegions.erase(activeRegions.begin() + regionIndex);
        regionIndex += step - 1;
        regionIndex %= activeRegions.size();
    } while (activeRegions.size() > 1);

    return activeRegions[0];
}

int getStep(int regionCount) {
    int step = 1;
    while (getLastRegion(regionCount, step) != 12)
        step++;
    return step;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << getStep(n) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}