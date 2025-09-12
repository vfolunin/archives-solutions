#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int stopCount;
    cin >> stopCount;

    if (!stopCount)
        return 0;

    vector<int> stopCoords(stopCount);
    for (int &stopCoord : stopCoords)
        cin >> stopCoord;

    sort(stopCoords.begin(), stopCoords.end());

    for (int i = stopCount - 1; i >= 0; i--)
        stopCoords.push_back(1422 * 2 - stopCoords[i]);

    for (int i = 1; i < stopCoords.size(); i++) {
        if (stopCoords[i] - stopCoords[i - 1] > 200) {
            cout << "IMPOSSIBLE\n";
            return 1;
        }
    }

    cout << "POSSIBLE\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}