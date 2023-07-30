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

    int testCount;
    cin >> testCount;

    vector<int> testPoints(testCount);
    for (int &points : testPoints)
        cin >> points;

    int addtitionalPoints, queryCount;
    cin >> addtitionalPoints >> queryCount;

    int maxPoints = 0;
    for (int i = 0; i < queryCount; i++) {
        int points = -2 * i, passedCount = 0;

        for (int j = 0; j < testCount; j++) {
            int passed;
            cin >> passed;

            if (passed) {
                points += testPoints[j];
                passedCount++;
            }
        }

        if (passedCount == testCount)
            points += addtitionalPoints;

        maxPoints = max(maxPoints, points);

        cout << maxPoints << "\n";
    }
}