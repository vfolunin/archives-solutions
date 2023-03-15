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

    map<int, map<int, int>> scoreCount;

    string name;
    int form, score;
    while (cin >> name >> name >> form >> score)
        scoreCount[form][score]++;

    for (auto &[form, scoreCount] : scoreCount)
        cout << scoreCount.rbegin()->second << " ";
}