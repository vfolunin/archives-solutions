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

    map<int, int> scoreSum, scoreCount;

    string name;
    int form, score;
    while (cin >> name >> name >> form >> score) {
        scoreSum[form] += score;
        scoreCount[form]++;
    }

    int bestScoreSum = 0, bestScoreCount = 1;
    for (auto &[form, scoreSum] : scoreSum) {
        if (scoreSum * bestScoreCount > bestScoreSum * scoreCount[form]) {
            bestScoreSum = scoreSum;
            bestScoreCount = scoreCount[form];
        }
    }

    for (auto &[form, scoreSum] : scoreSum)
        if (scoreSum * bestScoreCount == bestScoreSum * scoreCount[form])
            cout << form << " ";
}