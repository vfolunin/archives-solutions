#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int machineCount, int bSize, int aCount, int bCount, int time) {
    for (int i = 0; i < machineCount; i++) {
        int b = min(time / bSize, bCount);
        int a = min(time - bSize * b, aCount);
        bCount -= b;
        aCount -= a;
    }
    return !aCount && !bCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int bSize, machineCount, aCount, bCount;
    cin >> bSize >> machineCount >> aCount >> bCount;

    int l = -1, r = (aCount + bCount) * bSize;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(machineCount, bSize, aCount, bCount, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}