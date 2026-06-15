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

    int stationCount, moveCount;
    cin >> stationCount >> moveCount;

    int res;
    if (stationCount % 2 == 0) {
        if (moveCount < stationCount / 2)
            res = moveCount + 1;
        else
            res = stationCount / 2;
    } else {
        if (moveCount < stationCount - 1)
            res = moveCount + 1;
        else
            res = stationCount;
    }

    cout << res;
}