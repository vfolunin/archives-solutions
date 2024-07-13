#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<long long, long long> simulate(long long height, long long n, long long workerCount) {
    long long count = 1, totalCount = 1, totalHeight = height;
    while (height > 1) {
        if (height % (n + 1))
            return { -1, -1 };
        height /= n + 1;
        count *= n;
        totalCount += count;
        totalHeight += height * count;
    }
    if (count == workerCount)
        return { totalCount - workerCount, totalHeight };
    else
        return { -1, -1 };
}

bool solve() {
    long long initialHeight, workerCount;
    cin >> initialHeight >> workerCount;

    if (!initialHeight && !workerCount)
        return 0;

    for (long long n = 1; 1; n++) {
        auto [notWorkerCount, totalHeight] = simulate(initialHeight, n, workerCount);
        if (notWorkerCount == -1)
            continue;
        cout << notWorkerCount << " " << totalHeight << "\n";
        return 1;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}