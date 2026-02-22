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

    int targetCount, targetRows;
    cin >> targetCount >> targetRows;

    vector pWays(targetRows + 1, vector(targetCount + 1, vector<int>(targetCount + 1)));
    fill(pWays[0][0].begin(), pWays[0][0].end(), 1);

    for (int rows = 1; rows <= targetRows; rows++) {
        for (int count = 1; count <= targetCount; count++)
            for (int last = 1; last <= count; last++)
                pWays[rows][count][last] = pWays[rows - 1][count - last][last];

        for (int count = 1; count <= targetCount; count++)
            for (int last = 1; last <= targetCount; last++)
                pWays[rows][count][last] += pWays[rows][count][last - 1];
    }

    cout << pWays[targetRows][targetCount][targetCount];
}