#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int teamCount, gameCount;
    cin >> teamCount >> gameCount;

    if (!teamCount)
        return 0;

    int pointSum = 0;
    for (int i = 0; i < teamCount; i++) {
        string name;
        int points;
        cin >> name >> points;
        pointSum += points;
    }

    cout << gameCount * 3 - pointSum << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}