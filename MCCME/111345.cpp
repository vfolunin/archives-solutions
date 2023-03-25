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

    int minCount = 1e9;
    for (auto &[form, count] : count)
        minCount = min(minCount, count);

    for (auto &[form, count] : count)
        if (count == minCount)
            cout << form << " ";
}