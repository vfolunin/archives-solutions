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

    int photoCount, curTime, curDist;
    cin >> photoCount >> curTime >> curDist;

    int prevTime, prevDist, maxSpeed = 0;
    for (int i = 1; i < photoCount; i++) {
        prevTime = curTime;
        prevDist = curDist;
        cin >> curTime >> curDist;
        maxSpeed = max(maxSpeed, (curDist - prevDist) / (curTime - prevTime));
    }

    cout << maxSpeed;
}