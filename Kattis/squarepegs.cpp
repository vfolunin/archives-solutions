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

    int plotCount, circleCount, squareCount;
    cin >> plotCount >> circleCount >> squareCount;

    vector<int> plotDiametersSquared(plotCount);
    for (int &diameterSquared : plotDiametersSquared) {
        int radius;
        cin >> radius;

        diameterSquared = 4 * radius * radius;
    }

    vector<int> houseDiametersSquared(circleCount);
    for (int &diameterSquared : houseDiametersSquared) {
        int radius;
        cin >> radius;

        diameterSquared = 4 * radius * radius;
    }

    for (int i = 0; i < squareCount; i++) {
        int side;
        cin >> side;

        houseDiametersSquared.push_back(2 * side * side);
    }

    sort(plotDiametersSquared.begin(), plotDiametersSquared.end());
    sort(houseDiametersSquared.begin(), houseDiametersSquared.end());

    int res = 0;
    for (int plotDiameterSquared : plotDiametersSquared)
        res += (res < houseDiametersSquared.size() && houseDiametersSquared[res] < plotDiameterSquared);
    
    cout << res;
}