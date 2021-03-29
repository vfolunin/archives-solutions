#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool simulate(int coconutCount, int peopleCount) {
    for (int i = 0; i < peopleCount; i++) {
        if (coconutCount % peopleCount != 1)
            return 0;
        coconutCount--;
        coconutCount = coconutCount / peopleCount * (peopleCount - 1);
    }
    return coconutCount % peopleCount == 0;
}

bool solve() {
    int coconutCount;
    cin >> coconutCount;

    if (coconutCount < 0)
        return 0;

    int peopleCount = 10;
    while (peopleCount && !simulate(coconutCount, peopleCount))
        peopleCount--;

    cout << coconutCount << " coconuts, ";
    if (peopleCount)
        cout << peopleCount << " people and 1 monkey\n";
    else
        cout << "no solution\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}