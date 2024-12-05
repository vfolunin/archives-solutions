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

    int time, volume, flipCount;
    cin >> time >> volume >> flipCount;

    int lastFlipTime = 0, curVolume = 0;
    for (int i = 0; i < flipCount; i++) {
        int flipTime;
        cin >> flipTime;

        curVolume -= min(flipTime - lastFlipTime, curVolume);
        curVolume = volume - curVolume;
        lastFlipTime = flipTime;
    }

    curVolume -= min(time - lastFlipTime, curVolume);

    cout << curVolume;
}