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

    map<int, int> topScore;

    string name;
    int form, score;
    while (cin >> name >> name >> form >> score)
        topScore[form] = max(topScore[form], score);

    int maxScore = 0;
    for (auto &[form, score] : topScore)
        maxScore = max(maxScore, score);

    for (auto &[form, score] : topScore)
        if (score == maxScore)
            cout << form << " ";
}