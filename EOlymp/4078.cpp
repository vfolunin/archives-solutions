#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int colorCount, takeCount;
    if (!(cin >> colorCount >> takeCount))
        return 0;

    vector<int> ballCount(colorCount);
    int totalCount = 0;
    for (int &count : ballCount) {
        cin >> count;
        totalCount += count;
    }

    double res = 0;
    for (int color = 0; color < colorCount; color++) {
        double prob = 1;
        for (int i = 0; i < takeCount; i++)
            prob *= 1.0 * (ballCount[color] - i) / (totalCount - i);
        res += prob;
    }

    cout.precision(4);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}