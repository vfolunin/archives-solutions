#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int dayCount, bestTime, bestDist;
    if (!(cin >> dayCount >> bestTime >> bestDist))
        return 0;

    cout << "1\n";

    for (int i = 2; i <= dayCount; i++) {
        int time, dist;
        cin >> time >> dist;

        if (bestDist * time < dist * bestTime) {
            cout << i << "\n";
            bestTime = time;
            bestDist = dist;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}