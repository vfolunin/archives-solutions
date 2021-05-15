#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int instructionCount, sleepDelay, activateDelay;
    cin >> instructionCount >> sleepDelay >> activateDelay;

    int activeTime = 0, ignoredCount = 0, sleepCount = 0;

    for (int i = 0; i < instructionCount; i++) {
        int time;
        cin >> time;

        if (time < activeTime) {
            ignoredCount++;
            continue;
        }

        if (time - activeTime >= sleepDelay) {
            sleepCount++;
            activeTime = time + activateDelay;
        } else {
            activeTime = time;
        }
    }

    cout << "Case " << test << ": " << sleepCount << " " << ignoredCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}