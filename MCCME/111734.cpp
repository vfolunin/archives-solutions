#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int personCount, double carSpeed, double personSpeed, double personPos, double timeLimit) {
    personCount -= min(personCount, 4);
    double carTime = (personPos - timeLimit * personSpeed) / (carSpeed - personSpeed);
    double carPos = personPos - carTime * carSpeed;
    personPos -= carTime * personSpeed;
    timeLimit -= carTime;

    while (personCount) {
        carTime = (personPos - carPos) / (carSpeed + personSpeed);
        personPos -= carTime * personSpeed;
        timeLimit -= carTime;

        personCount -= min(personCount, 4);
        carTime = (personPos - timeLimit * personSpeed) / (carSpeed - personSpeed);
        carPos = personPos - carTime * carSpeed;
        personPos -= carTime * personSpeed;
        timeLimit -= carTime;
    }

    return timeLimit >= 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int personCount;
    double carSpeed, personSpeed, dist;
    cin >> personCount >> carSpeed >> personSpeed >> dist;

    if (carSpeed <= personSpeed) {
        cout << fixed << dist / personSpeed;
        return 0;
    }

    double l = 0, r = dist / personSpeed;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (can(personCount, carSpeed, personSpeed, dist, m))
            r = m;
        else
            l = m;
    }

    cout << fixed << r;
}