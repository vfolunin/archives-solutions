#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int personCount, groupSizeLimit;
    if (!(cin >> personCount >> groupSizeLimit))
        return 0;

    int groupSize = min(personCount, groupSizeLimit);
    while (groupSize > 1 && (personCount % groupSize || (personCount - 1) % (groupSize - 1)))
        groupSize--;

    if (groupSize == 1) {
        if (personCount > 1)
            cout << "No solution\n";
        else
            cout << "1 persons/group, 1 day\n";
    } else {
        int dayCount = (personCount - 1) / (groupSize - 1);
        cout << groupSize << " persons/group, ";
        cout << dayCount << " day" << (dayCount > 1 ? "s" : "") << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}