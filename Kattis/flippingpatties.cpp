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

    int orderCount;
    cin >> orderCount;

    map<int, int> actionCount;
    for (int i = 0; i < orderCount; i++) {
        int cookTime, serveTime;
        cin >> cookTime >> serveTime;

        actionCount[serveTime - 2 * cookTime]++;
        actionCount[serveTime - cookTime]++;
        actionCount[serveTime]++;
    }

    int maxActionCount = 0;
    for (auto &[_, count] : actionCount)
        maxActionCount = max(maxActionCount, count);

    cout << (maxActionCount + 1) / 2;
}