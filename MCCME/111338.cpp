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

    map<int, double> totalScore, scoreCount;

    string name;
    int form, score;
    while (cin >> name >> name >> form >> score) {
        totalScore[form] += score;
        scoreCount[form]++;
    }

    for (auto &[form, score] : totalScore)
        cout << fixed << score / scoreCount[form] << " ";
}