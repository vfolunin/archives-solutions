#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int lineCount;
    cin >> lineCount;

    if (!lineCount)
        return 0;

    cin.ignore();

    int minSpaceCount = 1e9, totalSpaceCount = 0;
    for (int i = 0; i < lineCount; i++) {
        string line;
        getline(cin, line);
        int spaceCount = count(line.begin(), line.end(), ' ');
        minSpaceCount = min(minSpaceCount, spaceCount);
        totalSpaceCount += spaceCount;
    }

    cout << totalSpaceCount - lineCount * minSpaceCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}