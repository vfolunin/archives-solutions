#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int planetCount;
    cin >> planetCount;

    if (!planetCount)
        return 0;

    string bestName;
    int bestYear = 1e9;

    for (int i = 0; i < planetCount; i++) {
        string name;
        int year, delta;
        cin >> name >> year >> delta;

        year -= delta;
        if (bestYear > year) {
            bestYear = year;
            bestName = name;
        }
    }

    cout << bestName << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}