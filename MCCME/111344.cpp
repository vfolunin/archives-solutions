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

    map<int, int> count;

    string name;
    int form, score;
    while (cin >> name >> name >> form >> score)
        count[form]++;

    int maxCount = 0;
    for (auto &[form, count] : count)
        maxCount = max(maxCount, count);

    for (auto &[form, count] : count)
        if (count == maxCount)
            cout << form << " ";
}