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
    int form, score, totalScoreSum = 0, totalScoreCount = 0;
    while (cin >> name >> name >> form >> score) {
        scoreSum[form] += score;
        scoreCount[form]++;
        totalScoreSum += score;
        totalScoreCount++;
    }

    for (auto &[form, scoreSum] : scoreSum)
        if (scoreSum * totalScoreCount > totalScoreSum * scoreCount[form])
            cout << form << " ";
}