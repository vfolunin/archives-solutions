#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int deviceCount, toggleCount, currentLimit;
    cin >> deviceCount >> toggleCount >> currentLimit;

    if (!deviceCount && !toggleCount && !currentLimit)
        return 0;

    vector<int> deviceCurrent(deviceCount);
    for (int &current : deviceCurrent)
        cin >> current;

    vector<int> isOn(deviceCount);
    int current = 0, maxCurrent = 0;
    for (int i = 0; i < toggleCount; i++) {
        int device;
        cin >> device;
        device--;

        isOn[device] ^= 1;
        if (isOn[device])
            current += deviceCurrent[device];
        else
            current -= deviceCurrent[device];

        maxCurrent = max(maxCurrent, current);
    }

    cout << "Sequence " << test << "\n";
    if (maxCurrent > currentLimit) {
        cout << "Fuse was blown.\n\n";
    } else {
        cout << "Fuse was not blown.\n";
        cout << "Maximal power consumption was " << maxCurrent << " amperes.\n\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}