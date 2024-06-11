#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int time;
    char problem;
    string verdict;

    unordered_map<char, int> solvedTime, penalty;

    while (cin >> time >> problem >> verdict) {
        if (solvedTime.count(problem))
            continue;
        if (verdict == "right")
            solvedTime[problem] = time;
        else
            penalty[problem] += 20;
    }

    int problemCount = 0, totalPenalty = 0;
    for (auto &[problem, time] : solvedTime) {
        problemCount++;
        totalPenalty += time + penalty[problem];
    }

    cout << problemCount << " " << totalPenalty;
}