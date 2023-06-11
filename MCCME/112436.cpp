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

    int studentCount;
    cin >> studentCount;

    map<int, map<int, int>> scoreCount;
    int bestScore = 0, bestScoreCount = 0;

    for (int i = 0; i < studentCount; i++) {
        string name;
        int form, score;
        cin >> name >> name >> form >> score;

        scoreCount[form][score]++;
        if (bestScore < score) {
            bestScore = score;
            bestScoreCount = 1;
        } else if (bestScore == score) {
            bestScoreCount = max(bestScoreCount, scoreCount[form][score]);
        }
    }

    for (auto &[form, scoreCount] : scoreCount)
        if (scoreCount.rbegin()->first == bestScore && scoreCount.rbegin()->second == bestScoreCount)
            cout << form << " ";
}