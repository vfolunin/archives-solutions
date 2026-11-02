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

    int coordCount, exitCoord;
    cin >> coordCount >> exitCoord;

    vector<int> coords(coordCount);
    for (int &coord : coords)
        cin >> coord;

    coords.push_back(-1001);
    coords.push_back(1001);
    sort(coords.begin(), coords.end());

    int ri = lower_bound(coords.begin(), coords.end(), 0) - coords.begin();
    int li = ri - 1;

    if (coords[li] < exitCoord && exitCoord <= coords[ri]) {
        cout << (exitCoord > 0 ? exitCoord : coords[ri] * 2 - exitCoord) << " ";
        cout << (exitCoord < 0 ? -exitCoord : -coords[li] * 2 + exitCoord);
    } else {
        cout << "Impossible";
    }
}