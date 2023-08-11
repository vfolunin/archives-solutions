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

    int coordCount;
    cin >> coordCount;

    vector<int> coords(coordCount);
    for (int &coord : coords)
        cin >> coord;

    int resCoord = 0;
    for (int i = 0; i + 1 < coordCount; i++)
        if (coords[resCoord + 1] - coords[resCoord] > coords[i + 1] - coords[i])
            resCoord = i;
    
    cout << coords[resCoord] << " " << coords[resCoord + 1];
}