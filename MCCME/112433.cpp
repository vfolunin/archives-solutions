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

    int totalCount;
    cin >> totalCount;

    map<int, int> scoreSum, scoreCount;
    int totalSum = 0;

    for (int i = 0; i < totalCount; i++) {
        string name;
        int form, score;
        cin >> name >> name >> form >> score;
        scoreSum[form] += score;
        scoreCount[form]++;
        totalSum += score;
    }

    vector<int> res;
    for (auto &[form, sum] : scoreSum)
        if (scoreSum[form] * totalCount > totalSum * scoreCount[form])
            res.push_back(form);

    for (int form : res)
        cout << form << " ";
    if (res.size() == 1)
        cout << "\n" << fixed << 1.0 * totalSum / totalCount;
}