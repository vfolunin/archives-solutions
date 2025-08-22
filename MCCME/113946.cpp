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

    int gapPercent, votedPercent;
    cin >> gapPercent >> votedPercent;

    int percentCount = 1000;
    int totalCount = 100 * percentCount;
    int votedCount = votedPercent * percentCount;
    int notVotedCount = totalCount - votedCount;

    int votedACount = votedCount / 100 * gapPercent;
    int votedBCount = (votedCount - votedACount) / 2;
    votedACount += votedBCount;

    if ((votedBCount + notVotedCount) - votedACount < percentCount) {
        cout << "Impossible";
        return 0;
    }

    int l = 0, r = notVotedCount;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;

        if ((votedBCount + m) - (votedACount + notVotedCount - m) < percentCount)
            l = m;
        else
            r = m;
    }

    cout << (100 * r + notVotedCount - 1) / notVotedCount;
}