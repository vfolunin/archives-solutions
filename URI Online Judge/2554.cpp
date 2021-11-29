#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int friendCount, dateCount;
    if (!(cin >> friendCount >> dateCount))
        return 0;

    string resDate;

    for (int j = 0; j < dateCount; j++) {
        string date;
        cin >> date;

        int visitorCount = 0;
        for (int j = 0; j < friendCount; j++) {
            int canVisit;
            cin >> canVisit;
            visitorCount += canVisit;
        }

        if (visitorCount == friendCount && resDate.empty())
            resDate = date;
    }

    if (!resDate.empty())
        cout << resDate << "\n";
    else
        cout << "Pizza antes de FdI\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}