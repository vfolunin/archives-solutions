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

    map<int, set<int>> scores;

    string name;
    int form, score;
    while (cin >> name >> name >> form >> score)
        scores[form].insert(score);

    for (auto &[form, scores] : scores)
        cout << *next(scores.rbegin()) << " ";
}