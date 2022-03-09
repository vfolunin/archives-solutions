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

    int problemCount, startProblem;
    cin >> problemCount >> startProblem;

    vector<int> problemTime(problemCount);
    for (int &time : problemTime)
        cin >> time;

    int totalTime = problemTime[startProblem], acCount = 0, penalty = 0;
    if (totalTime <= 300) {
        acCount++;
        penalty += totalTime;
    }

    problemTime[startProblem] = 1e9;
    sort(problemTime.begin(), problemTime.end());

    for (int time : problemTime) {
        if (totalTime + time <= 300) {
            totalTime += time;
            acCount++;
            penalty += totalTime;
        }
    }

    cout << acCount << " " << penalty;
}