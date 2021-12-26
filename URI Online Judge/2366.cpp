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

    int stationCount, maxDist;
    cin >> stationCount >> maxDist;

    vector<int> stationPos(stationCount);
    for (int &pos : stationPos)
        cin >> pos;
    stationPos.push_back(42195);

    for (int i = 0; i + 1 < stationPos.size(); i++) {
        if (stationPos[i + 1] - stationPos[i] > maxDist) {
            cout << "N\n";
            return 0;
        }
    }

    cout << "S\n";
}