#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &vesselVolume, int containerVolume, int containerCount) {
    int containers = 0, volume = 0;
    for (int v : vesselVolume) {
        if (volume + v <= containerVolume) {
            volume += v;
        } else {
            containers++;
            volume = v;
        }
    }
    containers += volume > 0;
    return containers <= containerCount;
}

bool solve() {
    int vesselCount, containerCount;
    if (!(cin >> vesselCount >> containerCount))
        return 0;

    vector<int> vesselVolume(vesselCount);
    for (int &v : vesselVolume)
        cin >> v;

    int l = *max_element(vesselVolume.begin(), vesselVolume.end()) - 1, r = 2e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(vesselVolume, m, containerCount))
            r = m;
        else
            l = m;
    }

    cout << r << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}