#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getTotalTime(int cycleTime, int speed, int distance) {
    int cycleDistance = cycleTime * speed;
    int fullCycleCount = (distance - 1) / cycleDistance;
    double remainingDistance = distance - cycleDistance * fullCycleCount;
    return fullCycleCount * cycleTime * 2 + cycleTime * remainingDistance / cycleDistance;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cycleTime1, speed1, cycleTime2, speed2, distance;
    cin >> cycleTime1 >> speed1 >> cycleTime2 >> speed2 >> distance;

    double totalTime1 = getTotalTime(cycleTime1, speed1, distance);
    double totalTime2 = getTotalTime(cycleTime2, speed2, distance);

    if (totalTime1 < totalTime2)
        cout << "First";
    else if (totalTime1 > totalTime2)
        cout << "Second";
    else
        cout << "Draw";
}