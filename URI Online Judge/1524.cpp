#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int studentCount, groupCount;
    if (!(cin >> studentCount >> groupCount))
        return 0;

    int positionA = 0, positionB = 0;
    vector<int> positionDelta;

    for (int i = 1; i < studentCount; i++) {
        positionA = positionB;
        cin >> positionB;
        positionDelta.push_back(positionB - positionA);
    }

    sort(positionDelta.rbegin(), positionDelta.rend());

    int groupSizeSum = positionB;
    for (int i = 0; i < groupCount - 1; i++)
        groupSizeSum -= positionDelta[i];

    cout << groupSizeSum << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}