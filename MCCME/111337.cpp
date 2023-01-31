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

    map<int, int> maxScore;

    string name;
    int form, score;
    while (cin >> name >> name >> form >> score)
        maxScore[form] = max(maxScore[form], score);

    for (auto &[form, score] : maxScore)
        cout << score << " ";
}