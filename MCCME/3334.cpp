#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

struct Participant {
    int region, score, wild;
};

bool can(vector<Participant> &participants, int maxWinnerCount, int limit) {
    int winnerCount = 0;
    unordered_set<int> presentedRegions, winnerRegions;
    for (auto &[region, score, wild] : participants) {
        if (wild || score >= limit) {
            winnerCount++;
            presentedRegions.erase(region);
            winnerRegions.insert(region);
        } else if (!winnerRegions.count(region)) {
            presentedRegions.insert(region);
        }
    }
    return winnerCount + presentedRegions.size() <= maxWinnerCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int participantCount, maxWinnerCount, regionCount;
    cin >> participantCount >> maxWinnerCount >> regionCount;

    vector<Participant> participants(participantCount);
    for (auto &[region, score, wild] : participants)
        cin >> region >> region >> score >> wild;

    int l = -1, r = 1e9;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (can(participants, maxWinnerCount, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}