#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int submissionCount;
    cin >> submissionCount;

    if (!submissionCount)
        return 0;

    map<string, multiset<pair<int, string>>> submissions;

    for (int i = 0; i < submissionCount; i++) {
        string problem, verdict;
        int time;
        cin >> problem >> time >> verdict;
        submissions[problem].insert({ time, verdict });
    }

    int acCount = 0, penalty = 0;

    for (auto &[problem, subs] : submissions) {
        int waCount = 0;
        for (auto &[time, verdict] : subs) {
            if (verdict == "correct") {
                acCount++;
                penalty += time + 20 * waCount;
            } else {
                waCount++;
            }
        }
    }

    cout << acCount << " " << penalty << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}