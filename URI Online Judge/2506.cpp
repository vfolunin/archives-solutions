#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int patientCount;
    if (!(cin >> patientCount))
        return 0;

    int screenTime = 420, criticalPatientCount = 0;
    for (int i = 0; i < patientCount; i++) {
        int h, m, criticalTime;
        cin >> h >> m >> criticalTime;

        int arrivalTime = h * 60 + m;
        while (screenTime < arrivalTime)
            screenTime += 30;

        criticalPatientCount += screenTime - arrivalTime > criticalTime;
        screenTime += 30;
    }

    cout << criticalPatientCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}